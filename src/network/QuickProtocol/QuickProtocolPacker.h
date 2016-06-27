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

#ifndef _QUICK_PROTOCOL_PACKER_H_
#define _QUICK_PROTOCOL_PACKER_H_

#include "memory/Buffer.h"

enum QUICKPROTOCOL_UNPACK_RESULT{
     QUICKPROTOCOL_UNPACK_OK = 0,
     QUICKPROTOCOL_UNPACK_NOTCOMPLETE,
     QUICKPROTOCOL_UNPACK_ERROR,
};


class QuickProtocolPacker
{
public:
    static bool packBuffer(Buffer * outputBuffer, unsigned char type, Buffer * dataBuffer);
    static QUICKPROTOCOL_UNPACK_RESULT unpackBuffer(Buffer * inputBuffer, unsigned char * type, Buffer * dataBuffer);
    
};

#endif // _QUICK_PROTOCOL_PACKER_H_
