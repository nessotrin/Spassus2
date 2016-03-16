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

#include "PacketMakerTests.h"
#include "network/PacketMaker.h"
#include "tools/ToCharNoEndian.h"
#include "tools/ChecksumGenerator.h"
#include "error/Error.h"
#include <CalcuLib.h>

void testPacketMaker()
{
    unsigned char tempDataBucket[50];
    unsigned char packetOriginalDataBuffer[] = {1,10,100,11,101,111};
    Buffer packetOriginalA(packetOriginalDataBuffer,6);
    Buffer packetOutputA(tempDataBucket,50);
    PacketMaker::generatePacket(&packetOriginalA,28,&packetOutputA);
    
    unsigned int dataSizeA;
    unsigned int packetIdA;
    unsigned int checksumA;
    
    ToCharNoEndian::charToUint(&dataSizeA,packetOutputA.getBuffer());
    ToCharNoEndian::charToUint(&packetIdA,packetOutputA.getBuffer()+4);
    ToCharNoEndian::charToUint(&checksumA,packetOutputA.getBuffer()+4+4+6);
    

    
    if(packetOutputA.getSize() != 4+4+6+4)
    {
        Error::crash((char *)"PACKET SIZE");
    }
    
    if(dataSizeA != 6)
    {
        Error::crash((char *)"DATA SIZE");
    }

    if(memcmp(packetOutputA.getBuffer()+4+4,packetOriginalDataBuffer,6))
    {
        Error::crash((char *)"DATA");
    }
    if(packetIdA != 28)
    {
        Error::crash((char *)"PACKET ID");
    }
    Buffer checkBuffer(packetOutputA.getBuffer(),4+4+6);
    if(checksumA != ChecksumGenerator::generateChecksum(&checkBuffer))
    {
        Error::crash((char *)"CHECKSUM");
    }
    
    
    
    if(PacketMaker::checkPacketCorruption(&packetOutputA))
    {
        Error::crash((char *)"FALSE CORRUPTION");
    }
    
    packetOutputA.getBuffer()[3] = 0xFF;

    if(!PacketMaker::checkPacketCorruption(&packetOutputA))
    {
        Error::crash((char *)"TRUE CORRUPTION SIZE");
    }
    
    packetOutputA.getBuffer()[3] = 0x00;
    packetOutputA.getBuffer()[4+4+6]++; //Checksum corruption
    
    if(!PacketMaker::checkPacketCorruption(&packetOutputA))
    {
        Error::crash((char *)"TRUE CORRUPTION CHECKSUM");
    }    
    packetOutputA.getBuffer()[4+4+6]--; //Checksum UNcorruption
    
    if(PacketMaker::getPacketId(&packetOutputA) != 28)
    {
        Error::crash((char *)"GET PACKET ID");
    }

    Buffer finalOutputPacket;
    PacketMaker::getPacketData(&packetOutputA,&finalOutputPacket);
    
    if(memcmp(finalOutputPacket.getBuffer(),packetOriginalDataBuffer,6))
    {
        Error::crash((char *)"GET PACKET DATA");
    }
    

}