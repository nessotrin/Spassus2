#include "Point.h"

#include <render/ScreenLine.h>

Point::Point()
{
    
}

Point::Point(Coord newCoord)
{
    coord = newCoord;
}

void Point::draw(Screen * screen)
{
    ScreenLine line;
    if(coord.getX() < 0 || coord.getY() < 0)
    {
        return;
    }
    if(screen->getScreenLine(&line, (unsigned int)coord.getY()))
    {
        return;
    }
    line.setPoint((unsigned int)coord.getX(),true);
}
