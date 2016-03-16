#include "PinSocket.h"

#include <CalcuLib.h>

NETWORK_SOCKET_RESULT PinSocket::writeOut(Buffer * toSend)
{
    if(Serial_GetTxBufferFreeCapacity() < toSend->getSize())
    {
        return NETWORK_SOCKET_OUT_OF_BUFFER;
    }
    
    unsigned int retry = 10;
    
    while(retry)
    {
        switch (Serial_WriteBytes(toSend->getBuffer(),toSend->getSize()))
        {
            case 0:
                return NETWORK_SOCKET_OK;
                break;
            case 3:
                connectionLost();
                if(isConnected == true)//got reconnected
                {
                    retry--;
                }
            case 2:
            default:;
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
    
    unsigned int retry = 10;
    
    while(retry)
    {
        switch (Serial_ReadBytes(inputBuffer->getBuffer(), inputBuffer->getSize(), &readSizeShort))
        {
            case 0:
                inputBuffer->setSize(readSizeShort);
                return NETWORK_SOCKET_OK;
                break;
            case 3:
                connectionLost();
                if(isConnected == true)//got reconnected
                {
                    retry--;
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

NETWORK_SOCKET_RESULT PinSocket::disconnect(bool discardWaitingData)
{
    //Serial_Close(discardWaitingData);
    return NETWORK_SOCKET_OK;
}

void PinSocket::connectionLost()
{
    printf("connection lost\n");
    isConnected = false;
    if(autoReconnect)
    {
        restartConnection();
    }
}

void PinSocket::restartConnection()
{
    printf("restarting connection \n");
    disconnect(true);
    printf("Attempting to connect ...\n");
    connect();
}