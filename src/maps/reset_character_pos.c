/*
** EPITECH PROJECT, 2018
** reset_character_pos.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"

void reset_character_pos(sfVector2f *pos)
{
	sfVector2f new_pos = {pos->x + 16, pos->y + 32};
	float y_lim = WIN_HEIGHT / 2 + WIN_HEIGHT / 4;

	if (pos->y < y_lim) {
		if (pos->x < WIN_WIDTH / 2)
			new_pos = \
project_iso_point((int)(MAP_X - 2) * SCALING_X, (int)(MAP_Y / 2) * SCALING_Y);
		if (pos->x > WIN_WIDTH / 2)
			new_pos = \
project_iso_point((int)((MAP_X / 2) - 2) * SCALING_X, (int)(MAP_Y - 3) * \
SCALING_Y);
	} else if (pos->y > y_lim) {
		if (pos->x < WIN_WIDTH / 2)
			new_pos = \
project_iso_point((int)(MAP_X / 2 - 1) * SCALING_X, (int)1 * SCALING_Y);
		if (pos->x > WIN_WIDTH / 2)
			new_pos = \
project_iso_point(2 * SCALING_X, (int)(MAP_Y / 2 - 2) * SCALING_Y);
	}
	pos->x = new_pos.x - 16;
	pos->y = new_pos.y - 32;
}
