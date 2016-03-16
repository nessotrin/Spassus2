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

#include <CalcuLib.h>

#include "QuickProtocol.h"

#include "network/PacketMaker.h"
#include "network/PacketMaker.h"
#include "memory/BufferOrganizer.h"

bool QuickProtocol::init()
{
    receiveQueue.setQueueSize(QUICKPROTOCOL_RECEIVEQUEUE_SIZE);
    sendQueue.setQueueSize(QUICKPROTOCOL_SENDQUEUE_SIZE);

    receiveOrganizer.setBufferCount(QUICKPROTOCOL_MAXMESSAGEWAITING);
    receiveOrganizer.setBufferMaxSize(QUICKPROTOCOL_MAXMESSAGESIZE);
    
    return (receiveQueue.allocPacketQueue() || sendQueue.allocPacketQueue() || receiveOrganizer.allocOrganizer());
}
void QuickProtocol::treatIncomming()
{
    unsigned char tempBufferData[QUICKPROTOCOL_MAXMESSAGESIZE];
    Buffer transfereBuffer(tempBufferData, QUICKPROTOCOL_MAXMESSAGESIZE);
    
    while(receiveQueue.getNextPacket(&transfereBuffer))
    {
        if(PacketMaker::checkPacketCorruption(&transfereBuffer))
        {
            printf("CORRUPTION /!\\n");
            continue;
        }
        
        unsigned int packetId = PacketMaker::getPacketId(&transfereBuffer);
        
        if(packetId < receiveIdCounter)
        {
            printf("OLD !!\n");
            continue;
        }
        
        if(packetId > receiveIdCounter+QUICKPROTOCOL_MAXMESSAGEWAITING)
        {
            printf("TOO FRESH !!\n");
            continue;
        }
        
        BUFFER_ORGANIZER_RESULT result = receiveOrganizer.addBuffer(&transfereBuffer,packetId);
        if(result == BUFFER_ORGANIZER_DUPLICATE)
        {
            printf("DUPLICATE !!\n");
            continue;
        }
        
        //TODO: SEND AND RECEIVE ACK HERE

    }
}


NETWORK_PROTOCOL_RESULT QuickProtocol::sendBuffer(Buffer * toSend)
{ //TODO: WAIT FOR ACK
    unsigned char packetBufferData[QUICKPROTOCOL_MAXMESSAGESIZE];
    Buffer packetBuffer(packetBufferData,QUICKPROTOCOL_MAXMESSAGESIZE);
    
    PacketMaker::generatePacket(toSend,sendIdCounter,&packetBuffer);
    sendIdCounter++;

    PACKET_QUEUE_RESULT result = sendQueue.addPacket(&packetBuffer);
    
    if(result == PACKET_QUEUE_OUTOFSPACE)
    {
        printf("OUT OF SPACE, REFUSING TO SEND\n");
        return NETWORK_PROTOCOL_OUT_OF_BUFFER;
    }
    
    return NETWORK_PROTOCOL_OK;
}

NETWORK_PROTOCOL_RESULT QuickProtocol::receiveBuffer(Buffer * inputBuffer)
{
    BUFFER_ORGANIZER_RESULT result = receiveOrganizer.getBuffer(inputBuffer,receiveIdCounter);
    if(result == BUFFER_ORGANIZER_NOBUFFER)
    {
        return NETWORK_PROTOCOL_NO_MESSAGE;
    }
    
    receiveIdCounter++;
    
    return NETWORK_PROTOCOL_OK;
}
    
bool QuickProtocol::connectProtocol(bool isMaster)
{
    unsigned char tempBufferData[64];
    Buffer tempBuffer(tempBufferData,64);
    
    if(isMaster)
    {
        memcpy(tempBufferData,"QUICK-MASTER",12);
        sendBuffer(&tempBuffer);
        
        tempBuffer.setSize(64);
        
        waitForABuffer(&tempBuffer);
        
        if(tempBuffer.getSize() == 11 && memcmp(tempBuffer.getBuffer(),"QUICK-SLAVE",11) == 0)
        {
            return false;
        }
    }
    else
    {
        waitForABuffer(&tempBuffer);
        
        if(tempBuffer.getSize() == 12 && memcmp(tempBuffer.getBuffer(),"QUICK-MASTER",12) == 0)
        {
            memcpy(tempBufferData,"QUICK-SLAVE",11);
            tempBuffer.setSize(11);
            
            sendBuffer(&tempBuffer);
            return false;
        }
    }
    
    return true;
}

bool QuickProtocol::disconnectProtocol(bool force)
{
    return false; //TODO implement an exit mean
}

void QuickProtocol::waitForABuffer(Buffer * tempBuffer)
{
    int timeout = 500;
    while(receiveBuffer(tempBuffer) == NETWORK_PROTOCOL_NO_MESSAGE && timeout)
    {
        flushSocket();
        treatIncomming();
        Sleep(100);
        timeout--;
    }
}