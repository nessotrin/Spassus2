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

#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(QuickProtocol newProtocol)
{
	protocol = newProtocol;
}

void NetworkHandler::tickHandler()
{
	protocol.updateProtocol();
	
	unsigned char data[64];
	Buffer receiveBuffer(data,64);
	unsigned char type;


	while(protocol.receiveMessage(&type,&receiveBuffer) == 0)
	{
		//printf("Received message, handling ... (Type %d)\n",type);
		handleEvent(type,&receiveBuffer);
	}
}

void NetworkHandler::handleEvent(unsigned char type, Buffer * buffer)
{
	for(unsigned int i = 0 ; i < subscriptionList.getSize() ; i++)
	{
		if(subscriptionList.get(i).type == type)
		{
			subscriptionList.get(i).receiver->networkEventHandler(type,buffer);
		}
	}
}

void NetworkHandler::registerHandler(NetworkEventReceiver * receiver, unsigned char type)
{
    NetworkEventSubscription newSubscription(receiver,type);
	for(unsigned int i = 0 ; i < subscriptionList.getSize() ; i++)
	{
		if(subscriptionList.get(i) == newSubscription)
		{
			Error::crash((char*)"NetworkHandler register | type is already registered by the same receiver");
		}
	}
	
	subscriptionList.add(newSubscription);
}

void NetworkHandler::unregisterHandler(NetworkEventReceiver * receiver, unsigned char type)
{
	NetworkEventSubscription toRemoveSubscription(receiver,type);
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
        Error::crash((char*)"NetworkHandler unregister | nothing to remove !");
    }
}

bool NetworkHandler::sendMessage(unsigned char type, Buffer * buffer)
{
    return protocol.sendMessage(type,buffer,10);
}
