#include <iostream>
#include "SDL.h"

// tag::init[]
int init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Init Error: %s\n", SDL_GetError());
			return 1;
		}
		SDL_Log("SDL initialised OK!\n");
		return 0;
}
// end::init[]

// tag::process_input[]
void process_input() {
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		"Processing Input.\n");
};
// end::process_input[]

// tag::update[]
void update() {
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		"Updating World.\n");
}
// end::update[]

// tag::render[]
void render() {
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		"Rendering World.\n");
}
// end::render[]

// tag::main[]
int main(int argc, char* argv[])
{
	bool running = false;
	if (init() == 0) running = true;

	while(running) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
			"Game Loop start: %i\n", SDL_GetTicks());
		process_input();
		update();
		render();

		//wait for some amount of time
	}
	return 0;
}
// end::main[]
