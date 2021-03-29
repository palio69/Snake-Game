#pragma once



#include <vector>
#include <SDL2/SDL.h>
#include <vec2f.hpp>
#include <image.hpp>
#include <map.hpp>



class snake {
private:
	image* spr;
	map tile_map;
	std::vector<vec2f> pos;

public:
	snake(SDL_Renderer* ren) :
		spr(new image(ren, "res/sprites.png", { 0, 0, 32, 16 }, { 0, 0, 64 * 4, 64 * 2 })),
		tile_map(map()),
		pos( { vec2f(2, 0), vec2f(1, 0), vec2f(0, 0) } ) { }
	~snake() { }

	image* get_spr() const { return this->spr; }
	const map& get_tile_map() const { return this->tile_map; }
	vec2f get_pos(unsigned i) const { return this->pos[i]; }

	void move_y(short move);

};