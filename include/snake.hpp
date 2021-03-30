#pragma once



#include <cstring>
#include <vector>
#include <SDL2/SDL.h>
#include <vec2f.hpp>
#include <image.hpp>
#include <map.hpp>



class snake {
private:
	image* spr;
	std::vector<vec2f> pos;
	int tw, th;
	unsigned dir;

public:
	snake(SDL_Renderer* ren, const int tw, const int th) :
		spr(new image(ren, "res/sprites.png", { 0, 0, 24, 8 }, { 0, 0, 0, 0 })),
		pos( { vec2f(2 * tw, 0 * th), vec2f(1 * tw, 0 * th), vec2f(0 * tw, 0 * th) } ),
		tw(tw), th(th),
		dir(2) { }
	~snake() { }

	image* get_spr() const { return this->spr; }
	vec2f get_pos(unsigned i) const { return this->pos[i]; }
	unsigned num_pos() const { return this->pos.size(); }

	void update(const Uint8* key, map& tile_map, const float delta_time);

};