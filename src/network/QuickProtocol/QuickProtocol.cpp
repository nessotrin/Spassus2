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
#include "QuickProtocol/QuickProtocolPacker.h"

#include "CalcuLib.h" //Sleep

QuickProtocol::QuickProtocol()
{
    receiveQueueBuffer.setBuffer(receiveQueueData);
    receiveQueueBuffer.setSize(RECEIVEQUEUESIZE);
}

NETWORK_PROTOCOL_RESULT QuickProtocol::sendMessage(unsigned char type, Buffer * dataBuffer, int timeout)
{
    unsigned char data[512];
    Buffer packedBuffer(data,512);
    
    
    if(QuickProtocolPacker::packBuffer(&packedBuffer,type,dataBuffer))
    {
        return NETWORK_PROTOCOL_ERROR;
    }
    
    
    NETWORK_SOCKET_RESULT result;
    result = socket->writeOut(&packedBuffer);
    int tryTime = 0;
    while(result == NETWORK_SOCKET_OUT_OF_BUFFER && tryTime >= timeout)
    {
        result = socket->writeOut(&packedBuffer);
        Sleep(SENDRETRYWAITMS);
        tryTime += SENDRETRYWAITMS;
    }
    
    if(RECEIVEQUEUESIZE-receiveQueueBuffer.getSize()>=packedBuffer.getSize())
    {
        memcpy(receiveQueueBuffer.getBuffer()+receiveQueueBuffer.getSize(),packedBuffer.getBuffer(),packedBuffer.getSize());
        receiveQueueBuffer.setSize(receiveQueueBuffer.getSize()+packedBuffer.getSize());
    }
    

    
    
    if(result != NETWORK_SOCKET_OK)
    {
        return NETWORK_PROTOCOL_ERROR;
    }
    
    return NETWORK_PROTOCOL_OK;
}



NETWORK_PROTOCOL_RESULT QuickProtocol::receiveMessage(unsigned char * type, Buffer * data)
{
    updateProtocol();
    
    if(receiveQueueBuffer.getSize() < 1+2+1)
    {
        return NETWORK_PROTOCOL_OUT_OF_BUFFER;
    }
    

    if(QuickProtocolPacker::unpackBuffer(&receiveQueueBuffer,type,data))
    {
        return NETWORK_PROTOCOL_ERROR;
    }
    
    
    return NETWORK_PROTOCOL_OK;
}


/*
 * 
 * Adds data from the socket to the queue
 * 
 */
NETWORK_PROTOCOL_RESULT QuickProtocol::updateProtocol()
{
    unsigned char data[RECEIVEQUEUESIZE];
    Buffer inputBuffer(data,RECEIVEQUEUESIZE-receiveQueueBuffer.getSize());
    
    if(socket->readIn(&inputBuffer) != NETWORK_PROTOCOL_OK)
    {
        return NETWORK_PROTOCOL_ERROR;
    }
    
    memcpy(receiveQueueBuffer.getBuffer()+receiveQueueBuffer.getSize(),inputBuffer.getBuffer(),inputBuffer.getSize());
    
    receiveQueueBuffer.setSize(receiveQueueBuffer.getSize()+inputBuffer.getSize());
    
    return NETWORK_PROTOCOL_OK;
}

void QuickProtocol::removeFromQueue(int size)
{
    memcpy(receiveQueueBuffer.getBuffer(),receiveQueueBuffer.getBuffer()+size,receiveQueueBuffer.getSize()-size);
    receiveQueueBuffer.setSize(receiveQueueBuffer.getSize()-size);
}