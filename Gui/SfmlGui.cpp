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

Chip16::SfmlGui::SfmlGui() {
    Gui();
    m_window = new sf::RenderWindow();
}

void Chip16::SfmlGui::Init(const char* title, Chip16::System* sys) {
    m_width = 320;
    m_height = 240;
    m_title.assign(title);
    m_cpu = sys->getCPU();
    m_gpu = sys->getGPU();
    m_spr_screen.setImage(m_gpu->getBuffer());
    m_scale = 1.0f;
    // Set up the SFML window
    m_window->Create(sf::VideoMode(320,240),m_title,sf::Style::Close);
    m_window->UseVerticalSync(true);
    m_window->SetFramerateLimit(60);
}

void Chip16::SfmlGui::Update() {
    m_window->Draw(m_spr_screen);
    m_window->Display();
}

Chip16::SfmlGui::Close() {
    delete m_window;
}

void Chip16::SfmlGui::setScale(int scale) {
    // Check the new scale is valid, apply it
    switch(scale) {
        case SCALE_1X:
            if(m_scale != scale)
                m_window->Create(sf::VideoMode(320,240),m_title,sf::Style::Close);
            m_spr_screen.SetScale(1.0f,1.0f);
            m_scale = scale;
            break;
        case SCALE_2X:
            if(m_scale != scale)
                m_window->Create(sf::VideoMode(640,480),m_title,sf::Style::Close);
            m_spr_screen.SetScale(2.0f,2.0f);
            m_scale = scale;
            break;
        case SCALE_4X:
            if(m_scale != scale)
                m_window->Create(sf::VideoMode(1280,960),m_title,sf::Style::Close);
            m_spr_screen.SetScale(4.0f,4.0f);
            m_scale = scale;
            break;
        case SCALE_FS:
            if(m_scale != scale)
                m_window->Create(VideoMode.GetDesktopMode(),m_title,sf::Style::Fullscreen);
            m_spr_screen.SetScale(2.0f,2.0f);
            m_scale = scale;
            break;
        default:
            std::cerr << "error: Invalid scaling parameter: " << scale << std::endl;
            break;
    }
}

