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

#include "Calculib.h" //Sleep

QuickProtocol::QuickProtocol()
{
    receiveQueueBuffer.setBuffer(receiveQueueData);
    receiveQueueBuffer.setSize(0);
}

NETWORK_PROTOCOL_RESULT QuickProtocol::sendMessage(unsigned char type, Buffer * dataBuffer, int timeout)
{
    unsigned char data[512];
    Buffer packedBuffer(data,512);
    
    
    if(QuickProtocolPacker::packBuffer(&packedBuffer,type,dataBuffer))
    {
        printf("Packing error ...\n");
        return NETWORK_PROTOCOL_ERROR;
    }
    
    
    NETWORK_SOCKET_RESULT result;
    result = socket->writeOut(&packedBuffer);
    int tryTime = 0;
    while(result == NETWORK_SOCKET_OUT_OF_BUFFER && tryTime < timeout)
    {
        result = socket->writeOut(&packedBuffer);
        Sleep(SENDRETRYWAITMS);
        tryTime += SENDRETRYWAITMS;
    }
    
    if(result != NETWORK_SOCKET_OK)
    {
        if(result == NETWORK_SOCKET_OUT_OF_BUFFER)
        {
            printf("No space in buffer !\n");
        }
        else
        {
            printf("Network error !\n");
        }
        return NETWORK_PROTOCOL_ERROR;
    }
    
    return NETWORK_PROTOCOL_OK;
}



NETWORK_PROTOCOL_RESULT QuickProtocol::receiveMessage(unsigned char * type, Buffer * data)
{    
    if(receiveQueueBuffer.getSize() < 1+2+1) // Smallest possible
    {
        return NETWORK_PROTOCOL_OUT_OF_BUFFER;
    }
    
	QUICKPROTOCOL_UNPACK_RESULT unpackResult = QuickProtocolPacker::unpackBuffer(&receiveQueueBuffer,type,data);
    if(unpackResult == QUICKPROTOCOL_UNPACK_ERROR)
    {
        receiveQueueBuffer.setSize(0); //trash the queue TODO: recovery ?
        
        
        return NETWORK_PROTOCOL_ERROR;
    }
	else if(unpackResult == QUICKPROTOCOL_UNPACK_NOTCOMPLETE)
	{
		return NETWORK_PROTOCOL_OUT_OF_BUFFER;
	}
    

    removeFromQueue(1+2+data->getSize()+1);
    
    return NETWORK_PROTOCOL_OK;
}


/*
 * 
 * Adds data from the socket to the queue
 * 
 */
NETWORK_PROTOCOL_RESULT QuickProtocol::updateProtocol()
{
    Buffer inputBuffer(receiveQueueBuffer.getBuffer()+receiveQueueBuffer.getSize(), //Directly pointing to the buffer
                       RECEIVEQUEUESIZE-receiveQueueBuffer.getSize());
    
    NETWORK_SOCKET_RESULT result = socket->readIn(&inputBuffer);
    
    if(result != NETWORK_SOCKET_OUT_OF_BUFFER)
    {
        return NETWORK_PROTOCOL_OK;
    }
    else if(result != NETWORK_SOCKET_OK) //ERROR
    {
        return NETWORK_PROTOCOL_ERROR;
    }
    
    if(inputBuffer.getSize() <= 0)
    {
        printf("BUG: Data but no data !\n");
        return NETWORK_PROTOCOL_ERROR;
    }
    
    //manually sync the new size
    receiveQueueBuffer.setSize(receiveQueueBuffer.getSize()+inputBuffer.getSize());
    
    return NETWORK_PROTOCOL_OK;
}

void QuickProtocol::removeFromQueue(unsigned int size)
{
    memmove(receiveQueueBuffer.getBuffer(),receiveQueueBuffer.getBuffer()+size,receiveQueueBuffer.getSize()-size);
    receiveQueueBuffer.setSize(receiveQueueBuffer.getSize()-size);
}