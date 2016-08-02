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

#include "MainMenu.h"

#include "ressource/bitmap/MainMenuBitmap.h"

//#include <MonochromeLib.h>

void MainMenu::setupMenu(Renderer * newRenderer, KeyboardReader * newKeyboardReader, NetworkHandler * newNetworkHandler)
{
    renderer = newRenderer;
    keyboardReader = newKeyboardReader;
    networkHandler = newNetworkHandler;
    dot.setup(renderer,networkHandler,keyboardReader);
    framerateLimiter.changeFramerate(20);
}

char MainMenu::loopMenu()
{
    initMenu();
    stop = 0;
    while(!stop)
    {
        keyboardReader->tick();
      //  networkHandler->tickHandler();
        renderMenu();
        framerateLimiter.wait();
        //tickCalcuLib();
    }
    deinitMenu();
    return result;
}

void MainMenu::initMenu()
{
    printf("Entering main menu\n");
    
    dot.init();
    
    keyboardReader->registerKey(this,KEY_CTRL_UP);
    keyboardReader->registerKey(this,KEY_CTRL_DOWN);
    keyboardReader->registerKey(this,KEY_CTRL_LEFT);
    keyboardReader->registerKey(this,KEY_CTRL_RIGHT);
    keyboardReader->registerKey(this,KEY_CTRL_EXE);
}

void MainMenu::deinitMenu()
{
    printf("Exiting main menu\n");
    
    dot.deinit();
    
    keyboardReader->unregisterKey(this,KEY_CTRL_UP);
    keyboardReader->unregisterKey(this,KEY_CTRL_DOWN);
    keyboardReader->unregisterKey(this,KEY_CTRL_LEFT);
    keyboardReader->unregisterKey(this,KEY_CTRL_RIGHT);
    keyboardReader->unregisterKey(this,KEY_CTRL_EXE);
}

void MainMenu::resetMenu()
{
    position = 0;
}

void MainMenu::renderMenu()
{
    Bdisp_AllClr_VRAM();
    //renderer->drawRect(Coord(coordX,coordY),buffer,Coord(16,8));
    //renderer->drawRect(Coord(0,0),(unsigned char *)mainMenuTexture,Coord(128,64));
    
    //renderer->drawLine(Coord(9,9),Coord(coordX,coordY),true);
    
    dot.render();
    
    //ML_horizontal_line(5,0,10,ML_BLACK);
    Bdisp_PutDisp_DD();
}

void MainMenu::keyHandler(int keyId, int keyStatus)
{
    if(keyStatus == 0)
    {
        return;
    }
    
    if(keyId == KEY_CTRL_UP)
    {
        /*
        if(result > 0)
        {
            result--;
        }
        */
        coordY--;
    }
    
    if(keyId == KEY_CTRL_DOWN)
    {
        /*
        if(result < 1)
        {
            result++;
        }
        */
        coordY++;
    }

    if(keyId == KEY_CTRL_LEFT)
    {
        /*
        if(result < 1)
        {
            result++;
        }
        */
        coordX--;
    }
    
    if(keyId == KEY_CTRL_RIGHT)
    {
        /*
        if(result < 1)
        {
            result++;
        }
        */
        coordX++;
    }

    if(keyId == KEY_CTRL_EXE)
    {
        //stop = 1;
    }
}