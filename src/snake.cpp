#include <snake.hpp>



void snake::move_y(short move) {
	std::string new_lvl = this->tile_map.get_lvl();
	// ...
	this->tile_map.set_lvl(new_lvl);
}