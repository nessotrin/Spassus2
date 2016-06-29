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

#include "KeyboardReader.h"

#include "memory/List.h"

#include "error/Error.h"

#include <Calculib.h>

void KeyboardReader::tick()
{
    for(unsigned int i = 0 ; i < subscriptionList.getSize() ; i++)
    {
        KeyboardSubscription currentSubscription = subscriptionList.get(i);
        bool keyStatus = IsKeyDown((unsigned short)currentSubscription.key);
        currentSubscription.receiver->keyHandler(currentSubscription.key,keyStatus);
    }
}

void KeyboardReader::registerKey(KeyEventReceiver * receiver, unsigned short key)
{
    KeyboardSubscription newSubscription(receiver,key);
    for(unsigned int i = 0 ; i < subscriptionList.getSize() ; i++)
    {
        if(subscriptionList.get(i) == newSubscription)
        {
            Error::crash((char*)"KeyboardReader register | key is already registered by the same receiver");
        }
    }
    subscriptionList.add(newSubscription);
}

void KeyboardReader::unregisterKey(KeyEventReceiver * receiver, unsigned short key)
{
    KeyboardSubscription toRemoveSubscription(receiver,key);
    bool found = false;
    for(unsigned int i = 0 ; i < subscriptionList.getSize() ; i++)
    {
        if(subscriptionList.get(i) == toRemoveSubscription)
        {
            subscriptionList.remove(i);
            found = true;
            break;
        }
    }
    if(!found)
    {
        Error::crash((char*)"KeyboardReader unregister | nothing to remove !");
    }
}