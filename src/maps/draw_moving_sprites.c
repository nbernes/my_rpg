/*
** EPITECH PROJECT, 2018
** draw_moving_sprites.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* draw_pnj(sfVector3f **map, sfRenderWindow* window, \
sfVector2i *cnt, sfClock *clock)
{
	sfVector2f pos = {0, 0};

	for (cnt->x = 0; cnt->x < MAP_X; cnt->x++) {
		if (map[cnt->y][cnt->x].z == 6) {
			pos.x =	map[cnt->y][cnt->x].x;
			pos.y =	map[cnt->y][cnt->x].y;
			window = set_mushroom(window, pos, clock);
		}
		if (!window)
			return (NULL);
	}
	return (window);
}

sfRenderWindow* draw_moving_sprites(sfVector3f **map, sfRenderWindow* window, \
type_stage_t stage, sfClock *clock)
{
	sfVector2i cnt;

	for (cnt.y = 0; stage == FRONTYARD && cnt.y < MAP_Y; cnt.y++) {
		draw_pnj(map, window, &cnt, clock);
		if (!window)
			return (NULL);
	}
	return (window);
}
