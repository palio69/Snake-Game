#pragma once



#include <vector>
#include <SDL2/SDL.h>
#include <vec2f.hpp>
#include <image.hpp>



class snake {
private:
	image spr;
	std::vector<vec2f> pos;

public:
	snake(SDL_Renderer* ren) :
		spr(ren, "res/sprites.png", { 0, 0, 32, 16 }, { 0, 0, 64 * 4, 64 * 2 } ),
		pos( { vec2f(2, 0), vec2f(1, 0), vec2f(0, 0) } ) { }
	~snake() { }

};