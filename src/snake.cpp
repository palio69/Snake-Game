#include <snake.hpp>



void snake::update(const Uint8* key, map& tile_map, const float delta_time) {
	static float acc = 0;

	if (key[SDL_SCANCODE_UP] && this->dir != 1)
		this->dir = 0;

	if (key[SDL_SCANCODE_DOWN] && this->dir != 0)
		this->dir = 1;

	if (key[SDL_SCANCODE_RIGHT] && this->dir != 3)
		this->dir = 2;

	if (key[SDL_SCANCODE_LEFT] && this->dir != 2)
		this->dir = 3;



	acc += delta_time;
	if (acc >= 0.25f)
		acc = 0;

	else
		return;



	vec2f old_head = this->pos[0];

	if (this->dir == 0)
		this->pos[0].y -= th;

	else if (this->dir == 1)
		this->pos[0].y += th;

	else if (this->dir == 2)
		this->pos[0].x += tw;

	else
		this->pos[0].x -= tw;

	for (int i = this->pos.size() - 1; i > 0; --i) {

		if (this->pos[i - 1] == this->pos[0])
			this->pos[i] = old_head;

		else
			this->pos[i] = this->pos[i - 1];


	}

	tile_map.new_fruit(this->pos[0]);

}