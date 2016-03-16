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

#include "PacketMaker.h"

#include "tools/ToCharNoEndian.h"
#include "tools/ChecksumGenerator.h"

bool PacketMaker::generatePacket(Buffer * dataBuffer, unsigned int id, Buffer * outputBuffer)
{
    if(outputBuffer->getSize() < dataBuffer->getSize()+4 +4 +4) //dataSize+ Id + Checksum
    {
        return true;
    }

    ToCharNoEndian::uintToChar(outputBuffer->getBuffer(),dataBuffer->getSize());
    ToCharNoEndian::uintToChar(outputBuffer->getBuffer()+4,id);      
    memcpy(outputBuffer->getBuffer()+4+4,dataBuffer->getBuffer(),dataBuffer->getSize());

    Buffer bufferWithoutSum(outputBuffer->getBuffer(),dataBuffer->getSize()+4+4);

    ToCharNoEndian::uintToChar(outputBuffer->getBuffer()+4+4+dataBuffer->getSize(),
                               ChecksumGenerator::generateChecksum(&bufferWithoutSum));
    
    outputBuffer->setSize(4+4+dataBuffer->getSize()+4); //Datasize+Id+Data+Checksum
    
    return false;
}
unsigned int PacketMaker::getPacketId(Buffer * inputBuffer)
{
    unsigned int packetId;
    ToCharNoEndian::charToUint(&packetId,inputBuffer->getBuffer()+4);
    return packetId;
}
bool PacketMaker::checkPacketCorruption(Buffer * inputBuffer)
{
    unsigned int dataSize;
    ToCharNoEndian::charToUint(&dataSize,inputBuffer->getBuffer());
    
    if(dataSize > MAX_PACKET_SIZE || dataSize < 0)
    {
        return true;
    }
    
    Buffer bufferWithoutSum(inputBuffer->getBuffer(),dataSize+8);
    
    unsigned int freshChecksum = ChecksumGenerator::generateChecksum(&bufferWithoutSum);
    unsigned int oldChecksum;
    ToCharNoEndian::charToUint(&oldChecksum, inputBuffer->getBuffer()+8+dataSize);

    if(freshChecksum != oldChecksum)
    {
        return true;
    }

    return false;
}
void PacketMaker::getPacketData(Buffer * inputBuffer, Buffer * outputBuffer)
{
    unsigned int size;
    ToCharNoEndian::charToUint(&size,inputBuffer->getBuffer());
    outputBuffer->setBuffer(inputBuffer->getBuffer()+4+4);
    outputBuffer->setSize(size);
}