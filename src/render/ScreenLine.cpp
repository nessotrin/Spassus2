#include "ScreenLine.h"

void ScreenLine::setup(unsigned char * newBuffer, unsigned int newStartBitOffset, unsigned int newLineLength)
{
    buffer = newBuffer;
    startBitOffset = newStartBitOffset;
    lineLength = newLineLength;
}

void ScreenLine::orPoint(unsigned int x, bool value)
{
    if(x >= lineLength)
    {
        return;
    }
    unsigned int bitPos = x + startBitOffset;
    buffer[bitPos>>3] |= ((unsigned int)value) << (bitPos&7);
}

void ScreenLine::setPoint(unsigned int x, bool value)
{
    if(x >= lineLength)
    {
        return;
    }
    unsigned int bitPos = x + startBitOffset;
    if(value)
    {
        buffer[bitPos>>3] |= 1 << (7-(bitPos&7)); // 7- => in-screen inverted bit order
    }
    else
    {
        buffer[bitPos>>3] &= ~(1 << (7-(bitPos&7)));
    }
}
IOBitBuffer ScreenLine::getAsIOBitBuffer()
{
    return IOBitBuffer(buffer,startBitOffset,lineLength);
}

unsigned int ScreenLine::getLength()
{
    return lineLength;
}

/*
#include <cstdio>
#include <error/Error.h>
bool ScreenLine::checkAndWrite(unsigned short * workBuffer, unsigned int * workBufferBitCount, unsigned int * outputWritePos, unsigned int outputWriteLength, unsigned int outputWriteStart)
{
    if(*workBufferBitCount == 0) // unecessary force write at the end
    {
        return false;
    }
    if(((*outputWritePos)&7) > 0 && *outputWritePos != outputWriteStart)
    {
        Error::crash("ScreenLine: checkAndWrite: Impossible A !");
        printf("Impossible: %d outputWritePos=%d outputWriteStart=%d workBufferBitCount=%d\n",((*outputWritePos)&7), *outputWritePos,outputWriteStart,*workBufferBitCount);
    }
    printf("Checking with %d\n",*workBufferBitCount);
    if(*outputWritePos == outputWriteStart && ((*outputWritePos)&7) > 0) //beggining
    {
        unsigned int bitCount = 8-((*outputWritePos)&7);
        bool endInStart = false; //special case where the end is in the start
        if(bitCount > outputWriteLength)
        {
            bitCount = outputWriteLength;
            endInStart = true;
        }
        printf("Beginning, outputWritePos=%d bitCount=%d\n",*outputWritePos,bitCount);
        if(*workBufferBitCount>=bitCount)
        {
            printf("Enter ...\n");
            unsigned char mask = 0xFF >> ((*outputWritePos)&7);
            unsigned int endInStartLeftShift = 0;
            if(endInStart) // extra mask to protect the end
            {
                endInStartLeftShift = 8-((*outputWritePos+outputWriteLength)&7);
                printf("End In Start ! %d \n",endInStartLeftShift);
                mask &= 0xFF << 8-((*outputWritePos+outputWriteLength)&7);
            }
            buffer[(*outputWritePos)>>3] &= (~mask);
            buffer[(*outputWritePos)>>3] |= (*workBuffer >> (*workBufferBitCount-bitCount) << endInStartLeftShift)&mask;
            *workBufferBitCount -= bitCount;
            *outputWritePos += bitCount;
            return true; //signal that the output is aligned
        }
    }
    else if((*outputWritePos)>>3 == (outputWriteStart+outputWriteLength)>>3 && ((outputWriteStart+outputWriteLength)&7) > 0) // end
    {
        printf("End with %d\n",*workBufferBitCount);
        unsigned int bitCount = (outputWriteStart+outputWriteLength)&7;
        if(*workBufferBitCount > bitCount)
        {
            printf("%d VS %d\n",*workBufferBitCount, bitCount);
            Error::crash("ScreenLine: checkAndWrite: Impossible B !");
        }
        if(*workBufferBitCount == bitCount)
        {
            unsigned char mask = ~(0xFF >> bitCount);        
            buffer[(*outputWritePos)>>3] &= ~mask;
            buffer[(*outputWritePos)>>3] |= (*workBuffer << (8 - *workBufferBitCount))&mask;                    
            *workBufferBitCount -= bitCount;
            *outputWritePos += bitCount;
        }
    }
    else // middle
    {
        if(*workBufferBitCount >= 8)
        {
            printf("Middle with %d\n",*workBufferBitCount);
            buffer[(*outputWritePos)>>3] = (*workBuffer >> (*workBufferBitCount-8));
            *outputWritePos += 8;
            *workBufferBitCount -= 8;
            return true;
        }
    }
    return false;
}
bool ScreenLine::addToBuffer(unsigned char toAdd, unsigned int toAddCount, unsigned short * workBuffer, unsigned int * workBufferBitCount, unsigned int * outputWritePos, unsigned int outputWriteLength, unsigned int outputWriteStart)
{
    printf("Add to buffer %d:  %d\n",toAddCount,toAdd);
    *workBuffer <<= toAddCount;
    *workBuffer |= toAdd;
    *workBufferBitCount += toAddCount;
    return checkAndWrite(workBuffer,workBufferBitCount,outputWritePos,outputWriteLength,outputWriteStart);
}
void ScreenLine::copyPoints(int x, unsigned char * source, unsigned int sourceStartBit, unsigned int sourceLength)
{
    //clip
    if(x < 0)
    {
        printf("Too left, clipping (%d)\n",-x);
        if(sourceLength > (unsigned int)(-x))// left clipping
        {
            sourceStartBit += -x;
            sourceLength -= -x;
            x = 0;
        }
        else // out of screen (end before the start)
        {
            return;
        }
    }
    if(x >= lineLength) //out of screen (starts after the end)
    {
        return;
    }
    if(x+sourceLength > lineLength) // too long, cut the end
    {
        printf("Too long, cutting %d to %d (%d)\n",sourceLength,lineLength-x,x);
        sourceLength = lineLength-x;
    }
    
    
    unsigned short workBuffer = 0;
    unsigned int workBufferBitCount = 0;
    const unsigned int bitPos = x + startBitOffset; //start bit of the write zone
    unsigned int writePos = bitPos;
    unsigned int readPosByte = sourceStartBit>>3;
    int endPosCompleteByte = ((sourceStartBit+sourceLength)>>3)-1;
    
    printf("START !\n");
    
    bool endInStart = false; // special case where the end is in the start
    
    //start
    unsigned int startBits = sourceStartBit&7;
    bool reachedAlignement = (startBits==0) && ((writePos&7) == 0); // check if aligned
    if(startBits > 0)
    {
        unsigned int bitCount = 8-startBits;
        printf("Unaligned bitmap Start ! (%d bits) \n",bitCount);
        unsigned char readMask = (0xFF>>startBits);
        unsigned char toAdd = source[readPosByte]&readMask;
        if(bitCount > sourceLength) //smaller than the byte
        {
            toAdd >>= bitCount-sourceLength;
            bitCount = sourceLength;
            endInStart = true;
        }
        reachedAlignement = addToBuffer(toAdd,bitCount,&workBuffer,&workBufferBitCount,&writePos,sourceLength,bitPos);
        readPosByte++;
    }
    
    //add to buffer until write is aligned (and is thus ready for the fast loop)
    while(!reachedAlignement && (int)readPosByte <= endPosCompleteByte)
    {
        printf("Reaching alignement ... (%d \ %d)\n",readPosByte,endPosCompleteByte);
        reachedAlignement = addToBuffer(source[readPosByte],8,&workBuffer,&workBufferBitCount,&writePos,sourceLength,bitPos);
        readPosByte++;
    }
    
    //Fast aligned loop
    for(;(int)readPosByte <= endPosCompleteByte; readPosByte++)
    {
        printf("FAST ALIGNED LOOP (%d / %d)\n",readPosByte,endPosCompleteByte);
        workBuffer <<= 8;
        workBuffer |= source[readPosByte];
        buffer[(writePos)>>3] = ((unsigned short)workBuffer >> (workBufferBitCount));
        writePos += 8;
    }
    
    //end
    unsigned int endBits = (sourceStartBit+sourceLength)&7;
    if(endBits > 0 && !endInStart)
    {
        unsigned char toAdd = (source[readPosByte] >> (8-endBits));
        addToBuffer(toAdd,endBits,&workBuffer,&workBufferBitCount,&writePos,sourceLength,bitPos);
    }
    
    checkAndWrite(&workBuffer,&workBufferBitCount,&writePos,sourceLength,bitPos); // flush the end bits
    
}

void ScreenLine::copyPoints(int x, unsigned char * source, unsigned int sourceStartBit, unsigned int sourceLength)
{
    //clip
    if(x < 0)
    {
        printf("Too left, clipping (%d)\n",-x);
        if((int)sourceLength+x > 0)// left clipping
        {
            sourceStartBit += -x;
            sourceLength -= -x;
            x = 0;
        }
        else // out of screen (end before the start)
        {
            return;
        }
    }
    if(x >= lineLength) //out of screen (starts after the end)
    {
        return;
    }
    if(x+sourceLength > lineLength) // too long, cut the end
    {
        printf("Too long, cutting %d to %d (%d)\n",sourceLength,lineLength-x,x);
        sourceLength = lineLength-x;
    }
    
    //maths
    unsigned int bitPos = x + startBitOffset; //start bit of the write zone
    unsigned int startShift = bitPos&7; // number of skiped start bit
    unsigned int endShift = (bitPos + sourceLength)&7; // number of NON-skiped end bit
    unsigned int destWritePos = bitPos>>3; // beginning of the write
    unsigned int sourceShift = sourceStartBit&7; // number of bit to skip in read
    int relativeShift = sourceShift-startShift; //bit to skip from write to reach read
    unsigned int sourceReadPos = sourceStartBit>>3; // beggining of read
    unsigned int destAlignedEndWritePos = ((bitPos+sourceLength)>>3)-1; // last aligned byte in write (end the middle section)
    bool startUnaligned = startShift > 0;
    bool endUnaligned = endShift > 0;
    unsigned short * sourceShort = (unsigned short *) source;
    

    
    //start
    if(startUnaligned)
    {
        unsigned short copyRealigned;
        //SPECIAL CASE: read is lefter than right
        if(relativeShift < 0)
        {
            copyRealigned = sourceShort[sourceReadPos] >> (-relativeShift); // align read with write BUT shift it the other way
            // NEXT BYTES ONLY : moves read 1 byte to the right to make right the leftest (does not work at the first byte, it would read before the buffer)
            relativeShift += 8;
            sourceReadPos -=1;
        }
        else
        {
            copyRealigned = *(sourceShort+sourceReadPos) << relativeShift; // align read with write
        }
        unsigned char mask = 0xFF >> startShift; // create a mask to protect the start of write
        if(sourceLength < 8-startShift) // the copy ends before the end of the first byte => mask the end too
        {
            mask &= 0xFF << (7-endShift); //endshift is the number of byte NOT TO hide 
        }
        buffer[destWritePos] &= ~mask; // erase
        buffer[destWritePos] |= copyRealigned&mask; // write        
        sourceReadPos++;
        destWritePos++;
    }
    //middle
    while(destWritePos <= destAlignedEndWritePos) // while in the middle (full byte copy)
    {
        unsigned short copyRealigned = *(sourceShort+sourceReadPos) << relativeShift;
        buffer[destWritePos] = copyRealigned; // copy full byte
        sourceReadPos++;
        destWritePos++;        
    }
    //end
    if(endUnaligned && sourceLength > 8-startShift) // if end is unaligned AND NOT in the same byte as start
    {
        unsigned short copyRealigned;
        if(relativeShift < 8)
        {
            copyRealigned = *(source+sourceReadPos) << relativeShift; //read a CHAR to prevent buffer OVERFLOW (since write is the leftest it needs LESS than write has in a byte)
        }
        else //SPECIAL CASE: read was lefter, read was moved to the read so right NEEDS 16 bits
        {
            copyRealigned = *(sourceShort+sourceReadPos) << relativeShift;// read was moved and is shifted MORE than a byte
        }
        copyRealigned = source[sourceReadPos] << relativeShift;
        unsigned char mask = ~(0xFF >> endShift);
        printf("endShift %d\n",endShift);
        buffer[destWritePos] &= ~mask; // erase
        buffer[destWritePos] |= copyRealigned&mask; // write        
        sourceReadPos++;
        destWritePos++;
    }

}

*/