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

#include <CalcuLib.h>

#include "QuickProtocolPacker.h"
#include "tools/TypeLimits.h"
#include "tools/ChecksumGenerator.h"
#include "tools/ToCharNoEndian.h"

bool QuickProtocolPacker::packBuffer(Buffer * outputBuffer, unsigned char type, Buffer * dataBuffer)
{
    if(1+2+dataBuffer->getSize()+1 > outputBuffer->getSize() || dataBuffer->getSize() > USHORT_LIMIT) // data oversize
    {
        return true;
    }
    
    outputBuffer->getBuffer()[0] = type;
    
    ToCharNoEndian::ushortToChar(outputBuffer->getBuffer()+1,dataBuffer->getSize());
    
    
    memcpy(1+2+outputBuffer->getBuffer(),dataBuffer->getBuffer(),dataBuffer->getSize());
    
    Buffer checksumBuffer(outputBuffer->getBuffer(),1+2+dataBuffer->getSize());
    unsigned char generatedChecksum = ChecksumGenerator::generateChecksum(&checksumBuffer);
    
    outputBuffer->getBuffer()[1+2+dataBuffer->getSize()] = generatedChecksum;
    
    return false;
}


/*
 * 
 * dataBuffer MUST BE PREALOCATED !
 * 
 */
QUICKPROTOCOL_UNPACK_RESULT QuickProtocolPacker::unpackBuffer(Buffer * inputBuffer, unsigned char * type, Buffer * dataBuffer)
{
    unsigned short dataSize;
    ToCharNoEndian::charToUshort(&dataSize,inputBuffer->getBuffer()+1);
    
    int packetSize = 1+2+dataSize+1;
    
    if(inputBuffer->getSize() < packetSize)
    {
        return QUICKPROTOCOL_UNPACK_NOTCOMPLETE;
    }
    Buffer checksumBuffer(inputBuffer->getBuffer(),packetSize-1);
    unsigned char generatedChecksum = ChecksumGenerator::generateChecksum(&checksumBuffer);    
    
    if(inputBuffer->getBuffer()[packetSize-1] != generatedChecksum) // checksum mismatch
    {
        return QUICKPROTOCOL_UNPACK_ERROR;
    }
    
    *type = inputBuffer->getBuffer()[0];
    
    memcpy(dataBuffer->getBuffer(),1+2+inputBuffer->getBuffer(),dataSize);
    dataBuffer->setSize(dataSize);

    
    return QUICKPROTOCOL_UNPACK_OK;
}