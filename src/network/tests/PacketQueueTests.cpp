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

#include "network/PacketQueue.h"
#include "error/Error.h"
#include <CalcuLib.h>


void testPacketQueue()
{
    PacketQueue packetQueue(512,0x60);
    if(packetQueue.allocatePacketQueue())
    {
        Error::crash((char *)"ALLOC");        
    }
    
    unsigned char testBufferStartA[8];
    strcpy((char *)testBufferStartA,"testAAA");
    unsigned char testBufferStartB[8];
    strcpy((char *)testBufferStartB,"testBBB");
    
    unsigned char testBufferStartC[] = {0,0,0,0x60}; 

    Buffer testBufferA(testBufferStartA,8);
    Buffer testBufferB(testBufferStartB,8);
    Buffer testBufferC(testBufferStartC,4);

    packetQueue.addPacket(&testBufferA);
    packetQueue.addQueueData(&testBufferC);
    packetQueue.addPacket(&testBufferB);
    packetQueue.addPacket(&testBufferA);

    unsigned char buffer[17];
    strcpy((char *)buffer,"ZZZZZZZZZZZZZZZZ");
    Buffer outputBuffer(buffer,16);
    
    packetQueue.getNextPacket(&outputBuffer);
    if(memcmp(buffer,"testAAA\0ZZZZZZZZ",16) || outputBuffer.getSize() != 8)
    {
        Error::crash((char *)"A");
    }
    packetQueue.removeLastPacket(outputBuffer.getSize());
    
    strcpy((char *)buffer,"ZZZZZZZZZZZZZZZZ");
    outputBuffer.setSize(16);
    
    packetQueue.getNextPacket(&outputBuffer);
    if(memcmp(buffer,"\0\0\0ZZZZZZZZZZZZZ",16) || outputBuffer.getSize() != 3)
    {
        Error::crash((char *)"B");
    }
    packetQueue.removeLastPacket(outputBuffer.getSize());
    
    strcpy((char *)buffer,"ZZZZZZZZZZZZZZZZ");
    outputBuffer.setSize(16);
    
    packetQueue.getNextPacket(&outputBuffer);
    if(memcmp(buffer,"testBBB\0ZZZZZZZZ",16) || outputBuffer.getSize() != 8)
    {
        Error::crash((char *)"C");
    }

    packetQueue.removeLastPacket(outputBuffer.getSize());
    
    strcpy((char *)buffer,"ZZZZZZZZZZZZZZZZ");
    outputBuffer.setSize(16);
    
    packetQueue.getNextPacket(&outputBuffer);
    if(memcmp(buffer,"testAAA\0ZZZZZZZZ",16) || outputBuffer.getSize() != 8)
    {
        Error::crash((char *)"D");
    }
    packetQueue.removeLastPacket(outputBuffer.getSize());

    packetQueue.freePacketQueue();
}

