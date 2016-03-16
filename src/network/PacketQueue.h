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

#ifndef _PACKETCUTTER_H_
#define _PACKETCUTTER_H_

#include "memory/Buffer.h"
#include <CalcuLib.h>


enum PACKET_QUEUE_RESULT{
    PACKET_QUEUE_OK = 0,
    PACKET_QUEUE_OUTOFSPACE,
    PACKET_QUEUE_OUTOFMESSAGE,
    PACKET_QUEUE_CORRUPTION,
};

class PacketQueue
{
private:
    unsigned char separator = 0x60;
    unsigned char * queueData = NULL;
    unsigned int queuePos = 0;
    unsigned int queueSize = 0;
    
    unsigned int findNextStop(unsigned int startPos);
    void moveBufferLeft(unsigned int amount);
    bool duplicateSeparator(Buffer * sourceBuffer, Buffer * outputBuffer); // 1=out of space
    bool unduplicateSeparator(Buffer * sourceBuffer, Buffer * outputBuffer); // 1=out of space
    
public:

    PacketQueue();
    PacketQueue(unsigned int newQueueSize,unsigned char newSeparator);
    
    bool allocPacketQueue();
    void freePacketQueue();
    
    void setQueueSize(unsigned int newQueueSize);
    void setSeparator(unsigned char newSeparator);
    
    PACKET_QUEUE_RESULT getNextPacket(Buffer * bufferToUse);
    void removeLastPacket(unsigned int size);
    
    PACKET_QUEUE_RESULT addPacket(Buffer * bufferToAdd);

    PACKET_QUEUE_RESULT addQueueData(Buffer * newData);
    unsigned char * getQueueData();
};

#endif // _PACKETCUTTER_H_
