#ifndef _QUICK_PROTOCOL_H_
#define _QUICK_PROTOCOL_H_

#include "memory/Buffer.h"

#include "network/NetworkProtocol.h"

//TODO:SET CORRECTLY DATA SIZE (512)


/*
 * DATA FORMAT
 * 
 *  TYPE         DATA SIZE           DATA          CHECKSUM
 *  1 Byte        2 Byte             X Byte         1 Byte
 * 
 */

#define RECEIVEQUEUESIZE 512
#define SENDRETRYWAITMS 10

class QuickProtocol : public NetworkProtocol
{
public:
    QuickProtocol();

    unsigned char receiveQueueData[RECEIVEQUEUESIZE];
    Buffer receiveQueueBuffer;
    
    NETWORK_PROTOCOL_RESULT sendMessage(unsigned char type, Buffer * dataBuffer, int timeout);
    NETWORK_PROTOCOL_RESULT receiveMessage(unsigned char * type, Buffer * dataBuffer);
    NETWORK_PROTOCOL_RESULT updateProtocol();
    void removeFromQueue(int size);

};

#endif // _QUICK_PROTOCOL_H_
