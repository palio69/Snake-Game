#include <snake.hpp>



void snake::update(const Uint8* key, const float delta_time) {
	if (key[SDL_SCANCODE_UP])
		dir = 0;

	if (key[SDL_SCANCODE_DOWN])
		dir = 1;

	if (key[SDL_SCANCODE_RIGHT])
		dir = 2;

	if (key[SDL_SCANCODE_LEFT])
		dir = 3;



	for (int i = this->pos.size() - 1; i > 0; --i)
		pos[i] = pos[i - 1];

	if (dir == 0)
		pos[0].y -= 1;

	else if (dir == 1)
		pos[0].y += 1;

	else if (dir == 2)
		pos[0].x += 1;

	else
		pos[0].x -= 1;

}