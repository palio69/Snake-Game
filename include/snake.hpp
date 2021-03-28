#pragma once



#include <SDL2/SDL.h>
#include <vec2f.hpp>
#include <image.hpp>



class snake {
private:
	image spr;
	std::vector<vec2f> pos;

public:
	snake() { }
	~snake() { }

};