#include <snake.hpp>



void snake::move_y(short move) {
	std::string new_lvl = this->tile_map.get_lvl();
	int pos = find_char(new_lvl, 'A'),
		w = this->tile_map.get_w(),
		x = pos % w,
		y = pos / w;

	const char chr = new_lvl[y * w + x];

	new_lvl[y * w + x] = '.';
	new_lvl[(y + move) * w + x] = chr;

	this->tile_map.set_lvl(new_lvl);
}