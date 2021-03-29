#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <image.hpp>
#include <map.hpp>
#include <snake.hpp>
#include <window.hpp>



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	const window win = window("Snake Game", 64 * 12, 64 * 7);

	int count = 0;

	snake snk = snake(win.get_ren());
	map tile_map = map();

	bool running = true;
	SDL_Event evn;

	while (running) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		if (++count == 100) {
			const Uint8* key = SDL_GetKeyboardState(nullptr);
			snk.update(key);
			count = 0;

		}

		win.clear();
		win.render(snk, tile_map);
		win.update();

	}

	SDL_Quit();
	IMG_Quit();
	return 0;
}