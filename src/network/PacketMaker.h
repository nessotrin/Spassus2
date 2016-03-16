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

#ifndef _PACKETMAKER_H_
#define _PACKETMAKER_H_

#include "memory/Buffer.h"

#define MAX_PACKET_SIZE 8192 //max data per packet

/* PACKET LAYOUT
 * 
 * DATA_SIZE 4Bytes - PACKET_ID 4Bytes - DATA XBytes - CHECKSUM 4Bytes 
 */


class PacketMaker
{
public:
    static bool generatePacket(Buffer * dataBuffer, unsigned int id, Buffer * outputBuffer);
    static unsigned int getPacketId(Buffer * inputBuffer);
    static bool checkPacketCorruption(Buffer * inputBuffer); // true = error
    static void getPacketData(Buffer * inputBuffer, Buffer * outputBuffer);

};

#endif // _PACKETMAKER_H_
