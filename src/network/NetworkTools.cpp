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

#include "NetworkTools.h"

#include <CalcuLib.h>

unsigned int NetworkTools::copyAndDuplicateBuffer(unsigned char * output, unsigned char * input, unsigned int size, unsigned char separator)
{
    int writePos = 0;
    for(int i = 0 ; i < size ; i++)
    {
        output[writePos] = input[i];
        if(input[i] == separator)
        {
            i--;
        }
        writePos++;
    }
    return writePos;
}

unsigned int NetworkTools::unduplicateBuffer(unsigned char * output, unsigned char * input, unsigned int size, unsigned char separator)
{
    int writePos = 0;
    for(int i = 0 ; i < size ; i++)
    {
        output[writePos] = input[i];
        if(input[i] == separator)
        {
            writePos--;
        }
        writePos++;
    }
    return writePos;
}

char NetworkTools::receiveBytesOrTimeout(NetworkSocket * socket,Buffer * inputBuffer, int timeout)
{
    NETWORK_SOCKET_RESULT result = NETWORK_SOCKET_OK;
    unsigned int readSize = 0;
    unsigned int totalReadSize = 0;
    unsigned int maxReadSize = inputBuffer->getSize();
    
    while(socket->getWaitingSize() < inputBuffer->getSize())
    {
        timeout--;
        if(timeout == 0)
        {
            return -1;
        }
    }
    
    if(socket->readIn(inputBuffer) == NETWORK_SOCKET_ERROR)
    {
        return -2;
    }

    return 0;

}

unsigned char NetworkTools::generateChecksum(unsigned char * buffer, unsigned int size)
{
    unsigned char checksum = 0xf;
    for(int i = 0 ; i < size ; i++)
    {
        checksum += buffer[i];
    }
    return checksum;
}
