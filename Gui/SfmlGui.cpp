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

#include <SFML/Graphics.hpp>
#include "SfmlGui.h"

Chip16::SfmlGui::Init(int w, int h)
 : m_width(w), m_height(h) {
    m_scale = 1.0f;
    // Set up the SFML window
    m_window = new sf::RenderWindow(sf::VideoMode(320,240),"mash16",sf::Style::Close);
    m_window->UseVerticalSync(true);
    m_window->SetFramerateLimit(60);
}

Chip16::SfmlGui::Close() {
    delete m_window;
}

Chip16::SfmlGui::setScale(int scale) {
    switch(scale) {
        case SCALE_1X:
            break;
        case SCALE_2X:
            break;
        case SCALE_4X:
            break;
        case SCALE_FS:
            break;
        default:
            // Error
            break;
    }
    // Apply the new scale
}