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

#ifndef _NETWORK_SOCKET_H
#define _NETWORK_SOCKET_H

#include "memory/Buffer.h"

enum NETWORK_SOCKET_RESULT{
    NETWORK_SOCKET_OK = 0,
    NETWORK_SOCKET_OUT_OF_BUFFER,
    NETWORK_SOCKET_ERROR,
};

class NetworkSocket{
  
protected:
    bool isConnected = false;
    bool autoReconnect = true;
public:
    virtual NETWORK_SOCKET_RESULT writeOut(Buffer * toSend) = 0;
    virtual NETWORK_SOCKET_RESULT readIn(Buffer * inputBuffer) = 0;
    virtual unsigned int getWaitingSize() = 0;
    virtual NETWORK_SOCKET_RESULT disconnect(bool doNotWaitForData) = 0;
    virtual NETWORK_SOCKET_RESULT connect() = 0;
  
};


#endif