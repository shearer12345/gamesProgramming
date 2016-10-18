#include <iostream>
#include "SDL.h"


// tag::globalVariables[]
bool running = false;
SDL_Window*	win = nullptr;
SDL_Renderer* ren = nullptr;
SDL_Texture* tex = nullptr;
// end::globalVariables[]

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


// tag::createWindow[]
void createWindow() {
	win = SDL_CreateWindow("A Window Title", 100, 100, 600, 600, SDL_WINDOW_SHOWN); //same height and width makes the window square ...

	//error handling
	if (win == nullptr) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_CreateWindow Error: %s\n", SDL_GetError());
			running = false;
		}
	SDL_Log("SDL Created Window OK!\n");
}
// end::createWindow[]

// tag::createRenderer[]
void createRenderer() {
	ren = SDL_CreateRenderer(win, -1, 0);

	//error handling
	if (ren == nullptr) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_CreateRenderer Error: %s\n", SDL_GetError());
			running = false;
		}
	SDL_Log("SDL CreateRenderer OK!\n");
}
// end::createRenderer[]

// tag::loadAssets[]
void loadAssets() {
	std::string imagePath = "./assets/Sdl-logo.bmp";

	SDL_Surface* surface = SDL_LoadBMP(imagePath.c_str());
	if (surface == nullptr) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_LoadBMP Error: %s\n", SDL_GetError());
			running = false;
	}
	else {
		SDL_Log("SDL_LoadBMP OK! for: %s\n", imagePath.c_str());
	}


	tex = SDL_CreateTextureFromSurface(ren, surface);
	if (tex == nullptr) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
			running = false;
	}
	else {
		SDL_Log("SDL_CreateTextureFromSurface OK!\n");

	}

	SDL_FreeSurface(surface);
}
// end::loadAssets[]

// tag::process_input[]
void process_input() {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Processing Input.\n");

	//Event-based input handling
	//The underlying OS is event-based, so **each** key-up or key-down (for example)
	//generates an event.
	//  - https://wiki.libsdl.org/SDL_PollEvent
	//In some scenarios we want to catch **ALL** the events, not just to present state
	//  - for instance, if taking keyboard input the user might key-down two keys during a frame
	//    - we want to catch based, and know the order
	//  - or the user might key-down and key-up the same within a frame, and we still want something to happen (e.g. jump)
	//  - the alternative is to Poll the current state with SDL_GetKeyboardState

	SDL_Event event; //somewhere to store an event

	//NOTE: there may be multiple events per frame
	//loop until SDL_PollEvent returns 0 (meaning no more events)
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = true;
			break;

		//keydown handling - we should to the opposite on key-up for direction controls (generally)
		case SDL_KEYDOWN:
			//Keydown can fire repeatable if key-repeat is on.
			//  - the repeat flag is set on the keyboard event, if this is a repeat event
			//  - in our case, we're going to ignore repeat events
			//  - https://wiki.libsdl.org/SDL_KeyboardEvent
			if (!event.key.repeat)
				switch (event.key.keysym.sym) {
					//hit escape to exit
					case SDLK_ESCAPE: running = false;
				}
			break;
		}
	}
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

	//First clear the renderer
	SDL_RenderClear(ren);

	//Draw the texture
	SDL_RenderCopy(ren, tex, NULL, NULL);

	//Update the screen
	SDL_RenderPresent(ren);
}
// end::render[]

// tag::main[]
int main(int argc, char* argv[])
{
	if (init() == 0) running = true;
	createWindow();
	createRenderer();
	loadAssets();

	// tag::gameloop[]
	while(running) {
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
			"Game Loop start: %i\n", SDL_GetTicks());

		process_input();
		update();
		render();
	}
	// end::gameloop[]

	return 0;
}
// end::main[]
