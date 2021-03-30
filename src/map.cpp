#include <map.hpp>



void map::new_fruit(const vec2f xy) {
	std::pair<int, int> comp = std::make_pair(xy.x, xy.y);
	if (comp != this->f)
		return;

	this->lvl[this->f.second * this->w + this->f.first] = '.';

	this->f.first = std::rand() % this->w;
	this->f.second = std::rand() % this->h;

	this->lvl[this->f.second * this->w + this->f.first] = 'O';
}