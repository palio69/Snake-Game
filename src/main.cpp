#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <image.hpp>
#include <map.hpp>
#include <snake.hpp>
#include <window.hpp>



#define W 24
#define H 14

#define TW 32
#define TH 32



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	std::srand(std::time(nullptr));

	const window win = window("Snake Game", W * TW, H * TH);

	int count = 0;

	snake snk = snake(win.get_ren());
	map tile_map = map(W, H, TW, TH);

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