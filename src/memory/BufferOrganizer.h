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

#ifndef _BUFFERORGANIZER_H_
#define _BUFFERORGANIZER_H_

#include "memory/Buffer.h"
#include <Calculib.h>

enum BUFFER_ORGANIZER_RESULT{
    BUFFER_ORGANIZER_OK = 0,
    BUFFER_ORGANIZER_OUTOFSPACE,
    BUFFER_ORGANIZER_NOBUFFER,
    BUFFER_ORGANIZER_DUPLICATE,
    BUFFER_ORGANIZER_BIGGERTHANMAX,
};


class BufferOrganizer
{
private:
    unsigned char * bufferHolder = NULL;
    unsigned int * bufferId = NULL;
    unsigned int * bufferSize = NULL;
    unsigned char * bufferPresence = NULL;

    unsigned int bufferCount = 0;
    unsigned int bufferMaxSize = 0;

public:
    BufferOrganizer();  
    BufferOrganizer(unsigned int newBufferCount, unsigned int newBufferMaxSize);    
    bool allocOrganizer();
    void freeOrganizer();
    
    void setBufferCount(unsigned int newBufferCount);
    void setBufferMaxSize(unsigned int newBufferMaxSize);
    
    bool isPresent(unsigned int id);
    BUFFER_ORGANIZER_RESULT addBuffer(Buffer * toAdd, unsigned int id);
    BUFFER_ORGANIZER_RESULT getBuffer(Buffer * outputBuffer, unsigned int wantedId);
    bool removeBuffer(unsigned int id);
    int searchForId(unsigned int id);
    int searchForSpace();
    

};

#endif // _BUFFERORGANIZER_H_
