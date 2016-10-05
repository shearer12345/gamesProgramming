#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	//send HelloWorld! to console output
	std::cout << "HelloWorld!\n";

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Log("SDL initialised OK!\n");

	return 0;
}
