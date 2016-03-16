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

#ifndef _NETWORKTOOLS_H_
#define _NETWORKTOOLS_H_

#include "network/NetworkSocket.h"

class NetworkTools
{
public:
    
    static unsigned int copyAndDuplicateBuffer(unsigned char * output, unsigned char * input, unsigned int size, unsigned char separator);
    static unsigned int unduplicateBuffer(unsigned char * output, unsigned char * input, unsigned int size, unsigned char separator);
    static unsigned char generateChecksum(unsigned char * buffer, unsigned int size);
    char receiveBytesOrTimeout(NetworkSocket * socket,Buffer * inputBuffer, int timeout);
    
};

#endif