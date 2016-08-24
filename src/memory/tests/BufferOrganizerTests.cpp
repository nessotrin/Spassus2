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

#include "BufferOrganizerTests.h"
#include "memory/BufferOrganizer.h"
#include "error/Error.h"


void testBufferOrganizer()
{
    BufferOrganizer organizer(3,10);
    
    if(organizer.allocOrganizer())
    {
        Error::crash((char *)"ALLOC");
    }
    
    unsigned char bufferAData[] = {0,1,2,3,4};
    unsigned char bufferBData[] = {42,69,96};
    unsigned char bufferCData[] = {0,1,2,3,4,5,6,7,8,9,10,11};

    unsigned char bufferTemp[50];
    Buffer bufferOutput(bufferTemp,50);
    Buffer bufferA(bufferAData,5);
    Buffer bufferB(bufferBData,3);
    Buffer bufferC(bufferCData,12);

    if(organizer.addBuffer(&bufferA,1) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"ADD A");
    }
    if(organizer.getBuffer(&bufferOutput,1) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"GET A");
    }
    if(memcmp(bufferOutput.getBuffer(),bufferA.getBuffer(),5) || bufferOutput.getSize() != 5)
    {
        printf("%d ->",bufferOutput.getSize());
        for(unsigned int i = 0 ; i < bufferOutput.getSize() ; i++)
        {
            printf("%d-%d |",bufferOutput.getBuffer()[i],bufferA.getBuffer()[i]);
        }
        Error::crash((char *)"CORRUPTED A");
        printf("\n");
    }
    bufferOutput.setSize(50);
    
    if(organizer.addBuffer(&bufferB,981724) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"ADD B");
    }
    if(organizer.addBuffer(&bufferA,2) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"ADD C");
    }
    if(organizer.addBuffer(&bufferA,3) != BUFFER_ORGANIZER_OUTOFSPACE)
    {
        Error::crash((char *)"OVERLOAD ERROR");
    }

    if(organizer.removeBuffer(2))
    {
       Error::crash((char *)"REMOVE C ERROR"); 
    }

    if(organizer.addBuffer(&bufferB,1) != BUFFER_ORGANIZER_DUPLICATE)
    {
        Error::crash((char *)"TRUE DUPLICATE ERROR");
    }

    if(organizer.addBuffer(&bufferB,2) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"ADD E ERROR");
    }
    
    if(organizer.removeBuffer(2))
    {
       Error::crash((char *)"REMOVE E ERROR"); 
    }

    if(organizer.removeBuffer(1))
    {
       Error::crash((char *)"REMOVE A ERROR"); 
    }


    if(organizer.addBuffer(&bufferC,44) != BUFFER_ORGANIZER_BIGGERTHANMAX)
    {
        Error::crash((char *)"ADD F ERROR");
    }

    if(organizer.getBuffer(&bufferOutput,981724) != BUFFER_ORGANIZER_OK)
    {
        Error::crash((char *)"GET B");
    }
    if(memcmp(bufferOutput.getBuffer(),bufferB.getBuffer(),3) || bufferOutput.getSize() != 3)
    {
        Error::crash((char *)"CORRUPTED B");
    }
    bufferOutput.setSize(50);

    if(organizer.removeBuffer(981724))
    {
       Error::crash((char *)"REMOVE B ERROR"); 
    }

    organizer.freeOrganizer();

}