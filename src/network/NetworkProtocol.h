#ifndef _NETWORK_PROTOCOL_H_
#define _NETWORK_PROTOCOL_H_

#include "memory/Buffer.h"
#include "NetworkSocket.h"

enum NETWORK_PROTOCOL_RESULT{
    NETWORK_PROTOCOL_OK = 0,
    NETWORK_PROTOCOL_OUT_OF_BUFFER,
    NETWORK_PROTOCOL_ERROR,
};

class NetworkProtocol
{

    
protected:
    bool isConnected = false;
    NetworkSocket * socket;
    
public:
    void setSocket(NetworkSocket * newSocket);
    
    virtual NETWORK_PROTOCOL_RESULT updateProtocol() = 0;
    
    

};

#endif // _NETWORK_PROTOCOL_H_
