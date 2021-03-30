#include <map.hpp>



void map::new_fruit(const vec2f xy) {
	if (xy.x != this->f.first * this->th || xy.y != this->f.second * this->th)
		return;

	this->lvl[this->f.second * this->w + this->f.first] = '.';

	this->f.first = std::rand() % this->w;
	this->f.second = std::rand() % this->h;

	this->lvl[this->f.second * this->w + this->f.first] = 'O';
}