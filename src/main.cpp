// robot-control-demo - demo MOARbots with a gamepad
// Copyright (C) 2015 Liam Marshall and others (for MOARbots)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <string>
#include <iostream>
#include <cstdlib>

#include <SDL.h>

const int JOYSTICK_DEADBAND = 8000;

SDL_Joystick* gameController;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
		std::cout << "SDL init error: " << SDL_GetError() << std::endl;
		return 1;
	}

	if (SDL_NumJoysticks() < 1) {
		std::cout << "No controllers plugged in." << std::endl <<
			"Please plug in a controller and run again." << std::endl;
		return 1;
	} else {
		gameController = SDL_JoystickOpen(0);
		if (gameController == NULL) {
			std::cout << "Unable to open game controller: " << std::endl <<
				"SDL error: " << SDL_GetError() << std::endl;
			return 1;  
		}
	}

	return 0;
}