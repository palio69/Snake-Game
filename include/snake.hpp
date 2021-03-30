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
	unsigned dir;

public:
	snake(SDL_Renderer* ren) :
		spr(new image(ren, "res/sprites.png", { 0, 0, 32, 16 }, { 0, 0, 0, 0 })),
		pos( { vec2f(2, 0), vec2f(1, 0), vec2f(0, 0) } ),
		dir(2) { }
	~snake() { }

	image* get_spr() const { return this->spr; }
	vec2f get_pos(unsigned i) const { return this->pos[i]; }
	unsigned num_pos() const { return this->pos.size(); }

	void update(const Uint8* key, const float delta_time);

};