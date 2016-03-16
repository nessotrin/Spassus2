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

#ifndef _LIST_H_
#define _LIST_H_

#include <CalcuLib.h>

#define MAX_LOST_LIMIT 100
#define MAX_PREALLOC_SIZE 100


template <class T> class List {
private:
    T * table = NULL;
    unsigned int size = 0;
    unsigned int allocSize = 0;

    void changeAllocSize(int addToSize);
    
    
    

public:
    T get(unsigned int id);
    void set(unsigned int id, T);
    void add(T);
    void remove(unsigned int id);
    void searchAndRemove(T data);
    unsigned int getSize();
    
    //tests
    unsigned int getAllocSize();
};


#include "error/Error.h"

template <class T> T List<T>::get(unsigned int id)
{
    if(id >= size)
    {
        Error::crash((char *)"List get  out of range id");
    }
    return table[id];
}

template <class T> void List<T>::set(unsigned int id, T data)
{
    if(id >= size)
    {
        Error::crash((char *)"List get  out of range id");
    }
    table[id] = data;
}

template <class T> void List<T>::add(T data)
{
    if(size+1 > allocSize) // out of slot
    {
        changeAllocSize(((int)(MAX_PREALLOC_SIZE)/sizeof(T))+1); // add more than enough
    }
    
    table[size] = data;
    size++;
}
template <class T> void List<T>::searchAndRemove(T data)
{
    for(unsigned int pos = 0 ; pos < size ; pos++)
    {
        if(table[pos] == data)
        {
            remove(pos);
            pos--;
        }
    }
}


template <class T> void List<T>::remove(unsigned int id)
{
    unsigned int lostSize = ((allocSize-size)+1);
    memmove(table+id,table+id+1,(size-id-1)*sizeof(T));
    if(lostSize*sizeof(T) > MAX_LOST_LIMIT) // too much waste
    {
        changeAllocSize((int)-lostSize); // remove until it's compact
    }
    size--;
}

template <class T> void List<T>::changeAllocSize(int countToAdd)
{
    allocSize += (unsigned int)countToAdd;
    if(allocSize > 0)
    {
        table = (T*)realloc(table,allocSize*sizeof(T));
        if(table == NULL)
        {
            Error::crash((char *)"List changeSize Out of memory");
        }
    }
    else
    {
        free(table);
        table = (T*)NULL;
    }
}

template <class T> unsigned int List<T>::getSize()
{
    return size;
}
template <class T> unsigned int List<T>::getAllocSize()
{
    return allocSize;
}

#endif