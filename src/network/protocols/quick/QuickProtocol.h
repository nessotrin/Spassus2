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

#ifndef _QUICK_PROTOCOL_H_
#define _QUICK_PROTOCOL_H_

#include "memory/Buffer.h"

#include <network/protocols/NetworkProtocol.h>

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
private:
    unsigned char receiveQueueData[RECEIVEQUEUESIZE]; //TODO: set as private
    Buffer receiveQueueBuffer;
    void removeFromQueue(unsigned int size);
    
public:
    QuickProtocol();
    
    NETWORK_PROTOCOL_RESULT sendMessage(unsigned char type, Buffer * dataBuffer, int timeout);
    NETWORK_PROTOCOL_RESULT receiveMessage(unsigned char * type, Buffer * dataBuffer);
    NETWORK_PROTOCOL_RESULT updateProtocol();

};

#endif // _QUICK_PROTOCOL_H_
