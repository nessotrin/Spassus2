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

#include "QuickProtocol.h"

#include "network/PacketMaker.h"



void QuickProtocol::readIncomming()
{
    unsigned char tempBufferData[QUICKPROTOCOL_MAXMESSAGESIZE];
    Buffer transfereBuffer(&tempBufferData, QUICKPROTOCOL_MAXMESSAGESIZE);
    
    while(receiveQueue->getNextPacket(transfereBuffer))
    {
        if(PacketMaker::checkPacketCorruption(transfereBuffer))
        {
            printf("CORRUPTION /!\\n");
            continue;
        }
        
        unsigned int packetId = PacketMaker.getPacketId();
        
        if(packetId < receiveIdCounter)
        {
            printf("OLD !!\n");
            continue;
        }
        
        if(packetId > receiveIdCounter+QUICKPROTOCOL_MAXMESSAGEWAITING)
        {
            printf("TOO FRESH !!\n");
        }
        
        RECEIVE_ORGANIZER_RESULT result = receiveOrganizer->addPacket(transfereBuffer);
        if(result == RECEIVE_ORGANIZER_DUPLICATE)
        {
            printf("DUPLICATE !!\n");
        }

    }
}

void QuickProtocol::sendOutcomming()
{
    
}

bool QuickProtocol::connectProtocol(bool isMaster)
{
    
}

bool QuickProtocol::disconnectProtocol(bool force)
{
    
}