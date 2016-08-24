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

#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Menu.h"

#include "world/object/DotObject.h"

class MainMenu : public Menu
{
public:

    void keyHandler(unsigned short keyId, bool keyStatus);
    void resetMenu();
    
    //overwrites
    void setupMenu(Screen * newScreen, KeyboardReader * newKeyboardReader, NetworkHandler * networkHandler);
    int loopMenu();
    
    enum mainMenuAction 
    {START_GAME = 0,
     QUIT = 1};
    
private:
    NetworkHandler * networkHandler;
    
    int coordX = 10;
    int coordY = 10;
    
    DotObject dot;

    void initMenu();
    void deinitMenu();
    char position;
    void renderMenu();
};
#endif