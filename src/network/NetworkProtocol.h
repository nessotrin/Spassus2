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

#ifndef _NETWORKPROTOCOL_H_
#define _NETWORKPROTOCOL_H_

#include "network/NetworkSocket.h"
#include "network/PacketQueue.h"
#include "memory/BufferOrganizer.h"
#include "memory/Buffer.h"

enum NETWORK_PROTOCOL_RESULT{
    NETWORK_PROTOCOL_OK = 0,
    NETWORK_PROTOCOL_OUT_OF_BUFFER,
    NETWORK_PROTOCOL_NO_MESSAGE,
    NETWORK_PROTOCOL_ERROR,
};

class NetworkProtocol
{
protected:
    PacketQueue receiveQueue;
    PacketQueue sendQueue;
    BufferOrganizer receiveOrganizer;
    NetworkSocket * protocolSocket;
    void flushSocket();
    virtual void treatIncomming() = 0;

public:
    
    virtual bool connectProtocol(bool isMaster) = 0;
    virtual bool disconnectProtocol(bool force) = 0;
    virtual NETWORK_PROTOCOL_RESULT sendBuffer(Buffer * toSend) = 0;
    virtual NETWORK_PROTOCOL_RESULT receiveBuffer(Buffer * inputBuffer) = 0;

};

#endif // _NETWORKPROTOCOL_H_
