#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <image.hpp>
#include <map.hpp>
#include <window.hpp>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	const window win = window("Snake Game", 64 * 12, 64 * 7);

	image sprites = image(win.get_ren(), "res/sprites.png", { 0, 0, 32, 16 }, { 0, 0, 64 * 4, 64 * 2 });
	map tile_map = map();

	bool running = true;
	SDL_Event evn;

	while (running) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		win.clear();
		win.render(sprites, tile_map);
		win.update();

	}

	SDL_Quit();
	IMG_Quit();
	return 0;
}