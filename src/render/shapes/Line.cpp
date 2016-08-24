#include "Line.h"


Line::Line()
{
    
}

Line::Line(Coord newCoordA, Coord newCoordB)
{
    coordA = newCoordA;
    coordB = newCoordB;
}

void Line::draw(Screen * screen)
{
    int xStart;
    int xEnd;
    int yStart;
    int yEnd;
    if(coordA.getY() <= coordB.getY())
    {
        xStart = coordA.getX();
        xEnd = coordB.getX();
        yStart = coordA.getY();
        yEnd = coordB.getY();
    }
    else
    {
        xStart = coordB.getX();
        xEnd = coordA.getX();
        yStart = coordB.getY();
        yEnd = coordA.getY();
    }
    
    float xPerY = (xEnd-xStart)/(float)(yEnd-yStart+1);
  //  xPerY -= xPerY/100.0f; //overrun correction
    printf("%d %d %d %d %f\n",xEnd,xStart,yEnd,yStart,xPerY);
    float x = xStart+0.5f;
    
    ScreenLine line;

    if(yEnd > 0 || yStart >= screen->getSize().getY()) // out of screen
    {
        return;
    }
    if(yStart < 0)
    {
        x += (-yStart)*xPerY;
        yStart = 0;
    }
    

    
    for(unsigned int y = (unsigned int)yStart ; y <= (unsigned int)yEnd ; y++)
    {
        if(screen->getScreenLine(&line,y))
        {
            continue;
        }

        float nextX = x + xPerY;        
        
        int startX = x <= nextX ? (int)x : (int)nextX;
        int endX = x <= nextX ? (int)nextX : (int)x;
        if(endX < 0 || startX >= (int)line.getLength()) //out of screen
        {
            continue;
        }
        if(startX < 0)
        {
            startX = 0;
        }
        if(endX >= (int)line.getLength())
        {
            endX = (int)line.getLength()-1;
        }
        for(unsigned int intX = (unsigned int)startX; intX <= (unsigned int) endX ; intX++)
        {
            line.setPoint(intX, 1);
        }
        
        x = nextX;
    }
}