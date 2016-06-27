#include "DotObject.h"

void DotObject::networkEventHandler(unsigned char type, Buffer * data) 
{
	x = (int) data->getBuffer()[0];
	y = (int) data->getBuffer()[1];
}

void DotObject::tick()
{
	
}