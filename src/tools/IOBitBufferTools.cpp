#include "IOBitBufferTools.h"

#include <memory/ShortFIFO.h>

#include <cstdio>
void IOBitBufferTools::copyOntoAt(int startBit, IOBitBuffer original, IOBitBuffer target)
{
    if(clipOntoAt(startBit, &original,&target))
    {
        return;
    }
    unsigned int bitCount;
    unsigned char buffer;
    ShortFIFO fifo;

    printf("1Target startBit %d, target length %d\n",target.getStartBit(),target.getLength());

    //first read
    original.readPartial(&buffer,&bitCount);
    if(bitCount == 0) //aligned bits, read a byte
    {
        original.readAligned(&buffer);
        bitCount = 8;
    }
    fifo.addNBits(buffer,bitCount);
    printf("1-Read %d\n",bitCount);

    //potential second read
    unsigned int requiered = target.getWritePartialSize();
    if(bitCount < requiered)
    {
        printf("Requiered is %d, have %d, more reading ..\n",requiered,bitCount);
        if(original.getLength() < 8)
        {
            original.readPartial(&buffer,&bitCount);
            fifo.addNBits(buffer,bitCount);
        }
        else
        {
            original.readAligned(&buffer);
            fifo.addByte(buffer);
            bitCount = 8; //for printf
        }
        printf("1E-Read %d\n",bitCount);
    }

    //first write
    if(requiered == 8)
    {
        fifo.getByte(&buffer);
        target.writeAligned(buffer);
    }
    else
    {
        fifo.getNBits(&buffer,requiered);
        target.writePartial(buffer);
    }
    printf("2-Write %d\n",requiered);
    
    
    printf("Original left: %d\n",original.getLength());
    //middle
    while(original.getLength() >= 8)
    {
        original.readAligned(&buffer);
        fifo.addByte(buffer);
                
        fifo.getByte(&buffer);
        target.writeAligned(buffer);
        //printf("3-Write 8\n");
    }

    //last read    
    if(original.getLength() > 0)
    {
        original.readPartial(&buffer,&bitCount);
        fifo.addNBits(buffer,bitCount);
        printf("4-Read %d\n",bitCount);        
    }

    //last write
    if(fifo.getBitCount() > 0)
    {
        requiered = target.getWritePartialSize();
        if(requiered == 8)
        {
            fifo.getByte(&buffer);
            target.writeAligned(buffer);
        }
        else
        {
            fifo.getNBits(&buffer,requiered);
            target.writePartial(buffer);            
        }
        printf("5-Write %d\n",requiered);
    }

    //potential extra last write (does not exist ?)
    if(fifo.getBitCount() > 0)
    {
        requiered = target.getWritePartialSize();
        fifo.getNBits(&buffer,requiered);
        target.writePartial(buffer);            
        printf("5E-Write %d\n",requiered);
    }
}

bool IOBitBufferTools::clipOntoAt(int startBit, IOBitBuffer * original, IOBitBuffer * target)
{
    if(startBit+(int)original->getLength() <= 0) // completely left
    {
        return true;
    }
    else if(startBit < 0) //partial left
    {
        unsigned int toMove = (unsigned int)(-(int)startBit);
        original->setStartBit(original->getStartBit()+toMove);
        original->setLength(original->getLength()-toMove);
        startBit = 0;
    }
    else if((unsigned int)startBit >= target->getLength()) //completely right
    {
        return true;
    }
    else if((unsigned int)startBit+original->getLength() >= target->getLength()) //partial right
    {
        original->setLength(target->getLength()- (unsigned int)startBit);
    }
    
    printf("Target start %d add %d\n",target->getStartBit(),startBit);
    target->setStartBit(target->getStartBit()+(unsigned int)startBit);
    target->setLength(original->getLength());
    
    return false;
}

