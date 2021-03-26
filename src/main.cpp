#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <window.hpp>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	const window win = window("Snake Game", 720, 480);

	bool running = true;
	SDL_Event evn;

	while (running) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		win.clear(100, 100, 0);
		win.update();

	}

	SDL_Quit();
	IMG_Quit();
	return 0;
}