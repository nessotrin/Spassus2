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

#include "FramerateLimiter.h"

#include "CalcuLib.h"

FramerateLimiter::FramerateLimiter(int newFramerate)
{
    changeFramerate(newFramerate);
}
FramerateLimiter::FramerateLimiter()
{
    
}

void FramerateLimiter::changeFramerate(int newFramerate)
{
    framerate = newFramerate;
    tickPerCycle = 128/framerate; //128 = System tick per second
}

int FramerateLimiter::getFramerate()
{
    return framerate;
}

void FramerateLimiter::wait()
{
    while(RTC_GetTicks()-lastTick < tickPerCycle && RTC_GetTicks() >= lastTick) //si RTC < last alors RTCa bouclé donc on libère
    {
        Sleep(5);
    }
    lastTick = RTC_GetTicks();
}