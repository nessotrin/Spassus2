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

#include "PinSocket.h"

#include <Calculib.h>

NETWORK_SOCKET_RESULT PinSocket::writeOut(Buffer * toSend)
{
    if(Serial_GetTxBufferFreeCapacity() < toSend->getSize())
    {
        return NETWORK_SOCKET_OUT_OF_BUFFER;
    }
    
    unsigned int tryCount = 0;
    
    while(tryCount < 10) //TODO: WTF logic is this ?
    {
        switch (Serial_WriteBytes(toSend->getBuffer(),toSend->getSize()))
        {
            case 0:
                return NETWORK_SOCKET_OK;
                break;
            case 3:
                printf("error: serial is disconnected !\n");
                if(isConnected)
                {
                    connectionLost();
                    if(autoReconnect)
                    {
                        reconnect();
                        if(isConnected == true)//got reconnected
                        {
                            tryCount++;
                        }
                    }
                }
            case 2:
            default:;
                printf("Serial ERROR !\n");
                return NETWORK_SOCKET_ERROR;
        }
    
    }


}
NETWORK_SOCKET_RESULT PinSocket::readIn(Buffer * inputBuffer)
{
    if(Serial_GetRxBufferSize() == 0 && isConnected)
    {
        inputBuffer->setSize(0);
        return NETWORK_SOCKET_OUT_OF_BUFFER;
    }

    short readSizeShort;
    
    unsigned int tryCount = 0;
    
    while(tryCount < 10)
    {
        switch (Serial_ReadBytes(inputBuffer->getBuffer(), inputBuffer->getSize(), &readSizeShort))
        {
            case 0:
                inputBuffer->setSize(readSizeShort);
                return NETWORK_SOCKET_OK;
                break;
            case 3:
                printf("error: serial is disconnected !\n");
                if(isConnected) //status says connected but serial says it's not
                {
                    connectionLost(); //signals the change and try to reconnect
                    if(autoReconnect)
                    {
                        reconnect();
                        if(isConnected == true)//got reconnected
                        {
                            tryCount++;
                        }
                    }
                }
                case 2:
            default:;
                return NETWORK_SOCKET_ERROR;
        }
    }
    

}

unsigned int PinSocket::getWaitingSize()
{
    return Serial_GetRxBufferSize();
}

NETWORK_SOCKET_RESULT PinSocket::connect()
{
    unsigned char config[] = {0, 5, 0, 0, 0, 0};
    if(Serial_Open(config) == 3)
    {
        return NETWORK_SOCKET_ERROR;
    }
    isConnected = true;
    return NETWORK_SOCKET_OK;
}

NETWORK_SOCKET_RESULT PinSocket::disconnect(bool doNotWaitForData)
{
    Serial_Close(doNotWaitForData);
    return NETWORK_SOCKET_OK;
}

void PinSocket::connectionLost()
{
    printf("connection lost\n");
    isConnected = false;
}

void PinSocket::reconnect()
{
    printf("restarting connection \n");
    disconnect(true);
    printf("Attempting to connect ...\n");
    connect();
}