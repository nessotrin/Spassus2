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

#include "BufferOrganizer.h"

#include <Calculib.h>


BufferOrganizer::BufferOrganizer()
{
    
}


BufferOrganizer::BufferOrganizer(unsigned int newBufferCount, unsigned int newBufferMaxSize)
{
    bufferCount = newBufferCount;
    bufferMaxSize = newBufferMaxSize;
}

void BufferOrganizer::setBufferCount(unsigned int newBufferCount)
{
    bufferCount = newBufferCount;
}

void BufferOrganizer::setBufferMaxSize(unsigned int newBufferMaxSize)
{
    bufferMaxSize = newBufferMaxSize;
}

bool BufferOrganizer::allocOrganizer()
{
    bufferHolder = (unsigned char *) malloc(bufferMaxSize*bufferCount);
    bufferId = (unsigned int *) malloc(4*bufferCount);
    bufferSize = (unsigned int *) malloc(4*bufferCount);
    bufferPresence = (unsigned char *) malloc(bufferCount);

    if(bufferHolder == NULL || bufferId == NULL || bufferSize == NULL || bufferPresence == NULL)
    {
        freeOrganizer();
        return true;
    }
    
    for(int i = 0 ; i < bufferCount ; i++)
    {
        bufferPresence[i] = 0;
    }
    
    return false;
}

void BufferOrganizer::freeOrganizer()
{
        free(bufferHolder);
        free(bufferId);
        free(bufferSize);
        free(bufferPresence);
}

bool BufferOrganizer::isPresent(unsigned int id)
{
    if(searchForId(id) != -1)
    {
        return true;
    }
    return false;
}    

BUFFER_ORGANIZER_RESULT BufferOrganizer::addBuffer(Buffer * toAdd, unsigned int id)
{
    if(searchForId(id) != -1)
    {
        return BUFFER_ORGANIZER_DUPLICATE;
    }
    
    int pos = searchForSpace();
    
    if(pos == -1)
    {
        return BUFFER_ORGANIZER_OUTOFSPACE;
    }
    
    if(toAdd->getSize() > bufferMaxSize)
    {
        return BUFFER_ORGANIZER_BIGGERTHANMAX;
    }
    
    memcpy(bufferHolder+(pos*bufferMaxSize),toAdd->getBuffer(),toAdd->getSize());
    bufferId[pos] = id;
    bufferPresence[pos] = 1;
    bufferSize[pos] = toAdd->getSize();
    
    return BUFFER_ORGANIZER_OK;
}

BUFFER_ORGANIZER_RESULT BufferOrganizer::getBuffer(Buffer * outputBuffer, unsigned int wantedId)
{
    int pos = searchForId(wantedId);
    if(pos == -1)
    {
        return BUFFER_ORGANIZER_NOBUFFER;
    }
    
    if(outputBuffer->getSize() < bufferSize[pos])
    {
        return BUFFER_ORGANIZER_OUTOFSPACE;
    }
    
    memcpy(outputBuffer->getBuffer(),bufferHolder+pos*bufferMaxSize,bufferSize[pos]);
    outputBuffer->setSize(bufferSize[pos]);
    
    return BUFFER_ORGANIZER_OK;
}

int BufferOrganizer::searchForId(unsigned int id)
{
    for(int i = 0 ; i < bufferCount ; i++)
    {
        if(bufferId[i] == id && bufferPresence[i] == 1)
        {
            return i;
        }
    }
    
    return -1;
}

int BufferOrganizer::searchForSpace()
{
    for(int i = 0 ; i < bufferCount ; i++)
    {
        if(bufferPresence[i] == 0)
        {
            return i;
        }
    }
    
    return -1;
}

bool BufferOrganizer::removeBuffer(unsigned int id)
{    
    int pos = searchForId(id);
    
    if(pos == -1)
    {
        return true;
    }
 
    bufferPresence[pos] = 0;    
    return false;
}