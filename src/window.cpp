#include <window.hpp>



void window::clear() const {
	SDL_RenderClear(this->ren);
}

void window::clear(const int r, const int g, const int b) const {
	SDL_SetRenderDrawColor(this->ren, r, g, b, 255);
	SDL_RenderClear(this->ren);
}

void window::clear(const int r, const int g, const int b, const int a) const {
	SDL_SetRenderDrawColor(this->ren, r, g, b, a);
	SDL_RenderClear(this->ren);
}

void window::render(const image& img) const {
	SDL_Rect src = img.get_src(),
		des = img.get_des();
	SDL_RenderCopy(this->ren, img.get_img(), &src, &des);
}

void window::render(const image& img, const map& tile_map) const {
	std::string lvl = tile_map.get_lvl();
	int w = tile_map.get_w(),
		h = tile_map.get_h(),
		tw = tile_map.get_tw(),
		th = tile_map.get_th();
	SDL_Rect src, des;

	for (int y = 0; y < h; ++y) {

		for (int x = 0; x < w; ++x) {

			if (lvl[y * w + x] == '.') {
				src = { 8, 8, 8, 8 };
				des = { x * 64, y * 64, 64, 64 };
				SDL_RenderCopy(this->ren, img.get_img(), &src, &des);

			}

		}

	}
}

void window::update() const {
	SDL_RenderPresent(this->ren);
}