#include "IOBitBuffer.h"

IOBitBuffer::IOBitBuffer(unsigned char * newBuffer, unsigned int newStartBit, unsigned int newLength)
{
    buffer = newBuffer;
    startBit = newStartBit;
    length = newLength;
}

unsigned int IOBitBuffer::getLength()
{
    return length;
}
void IOBitBuffer::setLength(unsigned int newLength)
{
    length = newLength;
}
unsigned int IOBitBuffer::getStartBit()
{
    return startBit;
}
void IOBitBuffer::setStartBit(unsigned int newStartBit)
{
    startBit = newStartBit;
}
#include <cstdio>
void IOBitBuffer::readPartial(unsigned char * byte, unsigned int * size)
{
    if(length == 0) //done reading
    {
        *size = 0;
        return;
    }
    if((startBit&7) > 0) //beginning
    {
        if(8-(startBit&7) > length) //end in beginning
        {
            *size = length;
            *byte = (buffer[startBit>>3]& (0xFF >> (startBit&7))) >> (8-((startBit&7)+length));
        }
        else
        {
            *size = 8-(startBit&7);
            *byte = buffer[startBit>>3]& (0xFF >> (startBit&7));
        }
    }
    else if(length < 8) //end
    {
        *size = length;
        *byte = buffer[startBit>>3] >> (8-length);
    }
    else //Middle, should not work here
    {
        *size = 0;
        return;
    }
    
    printf("Reading partial at %d (%db) (=%d) \n",startBit,*size,*byte);
    
    startBit += *size;
    length -= *size;
}

void IOBitBuffer::readAligned(unsigned char * byte)
{
    *byte = buffer[startBit>>3];
    startBit += 8;
    length -= 8;
}
#include <cstdio>
unsigned int IOBitBuffer::getWritePartialSize()
{
    printf("GetPartial at %d\n",startBit);
    if(length == 0) //done
    {
        return 0;
    }
    if((startBit&7) > 0) //beginning
    {
        if(length < 8-(startBit&7)) //end in beginning
        {
            return length;
        }
        printf("start %d\n",(8-(startBit&7)));
        return (8-(startBit&7));
    }
    else if(length < 8) //end
    {
        printf("End %d\n",length);
        return length;
    }
    else
    {
        return 8;
    }
}
#include <stdio.h>
void IOBitBuffer::writePartial(unsigned char byte)
{
    printf("Writing partial %d (%db) (at %d)\n",byte,getWritePartialSize(),startBit);
    unsigned int writeSize;
    if((startBit&7) > 0) //beginning
    {
        unsigned char mask;
        if(length < 8-(startBit&7)) //end in beginning
        {
            unsigned int rightGap = 8-((startBit&7)+length);
//            printf("End in beg\n");
            writeSize = length;
            mask = (0xFF >> (startBit&7)) & (0xFF << rightGap);
            buffer[startBit>>3] &= ~mask; //erase
            buffer[startBit>>3] |= (byte<<rightGap)&mask; //write

        }
        else
        {
            writeSize = 8-(startBit&7);
            mask = 0xFF >> (startBit&7);
            buffer[startBit>>3] &= ~mask; //erase
            buffer[startBit>>3] |= (byte)&mask; //write
        }
    }
    else if(length < 8) //end
    {
        writeSize = length;
        unsigned char mask = (unsigned char)( 0xFF << (8-length));
        buffer[startBit>>3] &= ~mask; //erase
        buffer[startBit>>3] |= (byte << (8-length))&mask; //write
    }
    else //Middle, should not work here
    {
        return;
    }
    
    startBit += writeSize;
    length -= writeSize;
}

void IOBitBuffer::writeAligned(unsigned char byte)
{
    buffer[startBit>>3] = byte;
    startBit += 8;
    length -= 8;
}

