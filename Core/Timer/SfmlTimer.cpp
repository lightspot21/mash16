/*
	Mash16 - an open-source C++ Chip16 emulator
    Copyright (C) 2011 Tim Kelsall

    Mash16 is free software: you can redistribute it and/or modify it under the terms 
	of the GNU General Public License as published by the Free Software Foundation, 
	either version 3 of the License, or  (at your option) any later version.

    Mash16 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
	PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program.
	If not, see <http://www.gnu.org/licenses/>.
*/

#include "SfmlTimer.h"

Chip16::SfmlTimer::SfmlTimer() { }

Chip16::SfmlTimer::~SfmlTimer() { }

uint32 Chip16::SfmlTimer::GetDt() {
    return (uint32)(m_timer.GetElapsedTime() * 1000000);
}

void Chip16::SfmlTimer::Reset() {
    m_timer.Reset();
}
