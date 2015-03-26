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

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL init error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Quit();
	return 0;
}