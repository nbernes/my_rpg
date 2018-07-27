/*
** EPITECH PROJECT, 2018
** draw_2d_map
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"

sfRenderWindow *display_each_object(sfRenderWindow *window, sfVector3f **map, \
sfVector2i *cnt, type_stage_t *stage)
{
	for (cnt->x = 0; cnt->x < MAP_X; cnt->x++) {
		window = check_if_object(map, window, cnt, stage);
		if (!window)
			return (NULL);
	}
	return (window);
}

sfRenderWindow *display_each_row(sfRenderWindow *window, sfVector3f **map, \
sfVector2i *cnt, type_stage_t stage)
{
	for (cnt->x = 0; cnt->x < MAP_X - 1; cnt->x++) {
		window = set_tiles(window, map, cnt, stage);
		if (window == NULL)
			return (NULL);
	}
	return (window);
}

sfRenderWindow *draw_map(sfVector3f **map, sfRenderWindow *window, \
type_stage_t stage)
{
	sfVector2i cnt;

	for (cnt.y = 0; cnt.y < MAP_Y - 1; cnt.y++) {
		window = display_each_row(window, map, &cnt, stage);
		if (!window)
			return (NULL);
	}
	for (cnt.y = 0; cnt.y < MAP_Y - 1; cnt.y++) {
		window = display_each_object(window, map, &cnt, &stage);
		if (!window)
			return (NULL);
	}
	return (window);
}
