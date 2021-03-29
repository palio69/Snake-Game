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



inline int find_char(std::string str, const char chr) {
	unsigned size = str.size();
	char* txt = new char[size];

	for (unsigned i = 0; i < size; ++i)
		txt[i] = str[i];

	const char* find = std::strchr(txt, chr);
	int rtrn;

	if (find == nullptr)
		rtrn = -1;

	else
		rtrn = find - txt;

	delete[] txt;
	return rtrn;
}