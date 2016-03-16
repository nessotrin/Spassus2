/*
Spassus2 is a free game (and powerfull engine) for Casio calculators
Copyright (C) 2016 Hugo KUENY

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "PacketQueue.h"


PacketQueue::PacketQueue()
{
    
}
PacketQueue::PacketQueue(unsigned int newQueueSize, unsigned char newSeparator)
{
    queueSize = newQueueSize;
    separator = newSeparator;
}

bool PacketQueue::allocatePacketQueue()
{
    queueData = (unsigned char *) malloc(queueSize);
    if(queueData == NULL)
    {
        return true;
    }
    return false;
}


void PacketQueue::freePacketQueue()
{
    free(queueData);
}
    
void PacketQueue::setSeparator(unsigned char newSeparator)
{
    separator = newSeparator;
}

void PacketQueue::setQueueSize(unsigned int newQueueSize)
{
    queueSize = newQueueSize;
}

unsigned int PacketQueue::findNextStop(unsigned int startPos)
{
    unsigned int comboStart;
    unsigned int comboLenght = 0;
    
    if(queuePos > 0)
    {
        for(unsigned int i = startPos ; i < queuePos ; i++)
        {
            if(queueData[i] == separator)
            {
                if(comboLenght == 0)
                {
                    comboStart = i;
                }
                comboLenght++;
            }
            else
            {
                if((comboLenght &1) == 1)
                {        
                    return comboStart;
                }
                comboLenght = 0;
            }
        }
    
        if((comboLenght &1) == 1)
        {
            return comboStart;
        }
    }


    return queueSize;
}

PACKET_QUEUE_RESULT PacketQueue::getNextPacket(Buffer * bufferToUse)
{
    unsigned int nextEnd = findNextStop(0);

    
    if(nextEnd == queueSize) // DO NOT give partial messages
    {
        return PACKET_QUEUE_OUTOFMESSAGE;
    }
    
    Buffer tempBuffer(queueData,nextEnd);
    
    
    if(unduplicateSeparator(&tempBuffer,bufferToUse))
    {
        return PACKET_QUEUE_OUTOFSPACE;
    }
    
    return PACKET_QUEUE_OK;
}

void PacketQueue::moveBufferLeft(unsigned int amount)
{
    memmove(queueData,queueData+amount,queuePos-amount);
    queuePos -= amount;
}

PACKET_QUEUE_RESULT PacketQueue::addPacket(Buffer * bufferToAdd)
{
    if(queueSize-queuePos < bufferToAdd->getSize()+1)
    {
        return PACKET_QUEUE_OUTOFSPACE;
    }

    Buffer tempBuffer(queueData+(queuePos),queueSize-queuePos);

    if(duplicateSeparator(bufferToAdd,&tempBuffer))
    {
        return PACKET_QUEUE_OUTOFSPACE;
    }
    
    queuePos += tempBuffer.getSize();
    
    queueData[queuePos] = separator;

    queuePos += 1;

    return PACKET_QUEUE_OK;
}

PACKET_QUEUE_RESULT PacketQueue::addQueueData(Buffer * newData)
{
    if(newData->getSize() > queueSize-queuePos)
    {
        return PACKET_QUEUE_OUTOFSPACE;
    }
    memcpy(queueData+queuePos,newData->getBuffer(),newData->getSize());
    queuePos += newData->getSize();
    return PACKET_QUEUE_OK;
}

bool PacketQueue::duplicateSeparator(Buffer * sourceBuffer, Buffer * outputBuffer)
{
    unsigned int readPos = 0;
    for(int i = 0 ; i < outputBuffer->getSize() ; i++)
    {
        if(readPos > sourceBuffer->getSize())
        {
            outputBuffer->setSize(i-1);
            return false;
        }
        outputBuffer->getBuffer()[i] = sourceBuffer->getBuffer()[readPos];
        if(sourceBuffer->getBuffer()[readPos] == separator)
        {
            i--;
        }
        readPos++;
    }
    
    return true;
}

bool PacketQueue::unduplicateSeparator(Buffer * sourceBuffer, Buffer * outputBuffer)
{
    unsigned int writePos = 0;
    for(int i = 0 ; i < sourceBuffer->getSize() ; i++)
    {
        if(writePos > outputBuffer->getSize())
        {
            return true;
        }
        outputBuffer->getBuffer()[writePos] = sourceBuffer->getBuffer()[i];
        writePos++;
        if(sourceBuffer->getBuffer()[i] == separator)
        {
            writePos--;
        }
    }
    outputBuffer->setSize(writePos);
    return false;
}


unsigned char * PacketQueue::getQueueData()
{
    return queueData;
}

void PacketQueue::removeLastPacket(unsigned int size)
{
    moveBufferLeft(size+1);// extra 1 separator byte 
}
