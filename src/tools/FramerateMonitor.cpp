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

#include "FramerateMonitor.h"

#include "Calculib.h"

void FramerateMonitor::tick()
{
    tickCount++;
 
    if(RTC_GetTicks() >= lastSecondTick+128) // 128= 1s constant
    {
        nextSecond();
    }
}
void FramerateMonitor::nextSecond()
{
    lastSecondTick = RTC_GetTicks();
    memmove(framerateHistory+1,framerateHistory,FRAMERATEMONITOR_HISTORY_SIZE-1);
    framerateHistory[0] = tickCount;
    tickCount = 0;
}

int FramerateMonitor::getFramerate()
{
    return framerateHistory[0];
}

int FramerateMonitor::getAverageFramerate()
{
    int value = 0;
    for(int i = 0 ; i < FRAMERATEMONITOR_HISTORY_SIZE ; i++)
    {
        value += framerateHistory[i];
    }
    
    return value/FRAMERATEMONITOR_HISTORY_SIZE;
}

int * FramerateMonitor::getFramerateHistory()
{
    return framerateHistory;
}