#ifndef _DOT_OBJECT_H_
#define _DOT_OBJECT_H_

#include "Object.h"

#include "network/NetworkEventReceiver.h"

class DotObject  : public Object, public NetworkEventReceiver
{
private:
	int x;
	int y;

public:

    void networkEventHandler(unsigned char type, Buffer * data) ;
	void tick();
};

#endif // _DOT_OBJECT_H_
