/*
** EPITECH PROJECT, 2018
** check_if_behind_obst.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"

void compare_h_to_big_obj(sfRenderWindow *window, scene_t *scene, \
sfVector2f pos, sfVector2i *cnt)
{
	float tile_center_height = scene->map[cnt->y + 3][cnt->x + 3].y - \
(scene->map[cnt->y + 3][cnt->x + 3].y - scene->map[cnt->y][cnt->x].y) / 2;

	if (pos.y < tile_center_height && tile_center_height - pos.y < 200) {
		pos.x = scene->map[cnt->y][cnt->x].x;
		pos.y = scene->map[cnt->y][cnt->x].y;
		window = check_if_object(scene->map, window, cnt, \
&scene->stage);
	}
}

void compare_h_to_medium_obj(sfRenderWindow *window, scene_t *scene, \
sfVector2f pos, sfVector2i *cnt)
{
	float tile_center_height = scene->map[cnt->y + 2][cnt->x + 2].y - \
(scene->map[cnt->y + 2][cnt->x + 2].y - scene->map[cnt->y][cnt->x].y) / 2;

	if (pos.y < tile_center_height && tile_center_height - pos.y < 200) {
		pos.x = scene->map[cnt->y][cnt->x].x;
		pos.y = scene->map[cnt->y][cnt->x].y;
		window = check_if_object(scene->map, window, cnt, \
&scene->stage);
	}
}

void compare_h_to_small_obj(sfRenderWindow *window, scene_t *scene, \
sfVector2i *cnt, sfVector2f pos)
{
	float tile_center_height = scene->map[cnt->y + 1][cnt->x + 1].y - \
(scene->map[cnt->y + 1][cnt->x + 1].y - scene->map[cnt->y][cnt->x].y) / 2;

	if (pos.y < tile_center_height && tile_center_height - pos.y < 120) {
		pos.x = scene->map[cnt->y][cnt->x].x;
		pos.y = scene->map[cnt->y][cnt->x].y;
		if (scene->map[cnt->y][cnt->x].z == 6 && scene->stage \
== FRONTYARD)
			window = set_mushroom(window, pos, scene->pnj);
		window = check_if_object(scene->map, window, cnt,	\
&scene->stage);
	}
}

void check_if_behind_obst(sfRenderWindow *window, scene_t *scene, \
sfVector2i *cnt, sfVector2f pos)
{
	switch (scene->stage) {
	case PANTRY:
		check_if_behind_pantry(window, scene, cnt, pos);
		break;
	case GARDEN:
		check_if_behind_garden(window, scene, cnt, pos);
		break;
	case FRONTYARD:
		check_if_behind_frontyard(window,	\
scene, cnt, pos);
		break;
	default:
		break;
	}
}

int go_through_each_obst(sfRenderWindow *window , sfVector2f pos, \
scene_t *scene)
{
	sfVector2i cnt;

	pos.x += 16;
	pos.y += 32;
	for (cnt.y = 0; cnt.y < MAP_Y - 1; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X - 1; cnt.x++)
			check_if_behind_obst(window, scene, &cnt, pos);
	}
	if (window == NULL)
		return (ERROR);
	else
		return (OK);
}
