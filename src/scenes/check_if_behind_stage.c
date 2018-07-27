/*
** EPITECH PROJECT, 2018
** check_if_behind_garden.c
** File description:
** ...
*/

#include "proto.h"

void check_if_behind_frontyard(sfRenderWindow *window, scene_t *scene, \
sfVector2i *cnt, sfVector2f pos)
{
	if (scene->map[cnt->y][cnt->x].z > 0 && pos.x > \
scene->map[cnt->y + 1][cnt->x].x  - 65 && pos.x < \
scene->map[cnt->y][cnt->x + 1].x + 50) {
		if (scene->map[cnt->y][cnt->x].z == 5)
			compare_h_to_medium_obj(window, scene, pos, cnt);
		else if (scene->map[cnt->y][cnt->x].z > 6)
			compare_h_to_big_obj(window, scene, pos, cnt);
		else
			compare_h_to_small_obj(window, scene, cnt, pos);
	}
}

void check_if_behind_pantry(sfRenderWindow *window, scene_t *scene, \
sfVector2i *cnt, sfVector2f pos)
{
	if (scene->map[cnt->y][cnt->x].z > 0 && pos.x > \
scene->map[cnt->y + 1][cnt->x].x  - 30 && pos.x < \
scene->map[cnt->y][cnt->x + 1].x + 30) {
		switch ((int)scene->map[cnt->y][cnt->x].z) {
		case 7:
		case 5:
			compare_h_to_medium_obj(window, scene, pos, cnt);
			break;
		default:
			compare_h_to_small_obj(window, scene, cnt, pos);
			break;
		}
	}
}

void check_if_behind_garden(sfRenderWindow *window, scene_t *scene, \
sfVector2i *cnt, sfVector2f pos)
{
	if (scene->map[cnt->y][cnt->x].z > 0 && \
scene->map[cnt->y][cnt->x].z < 7 && pos.x > \
scene->map[cnt->y + 1][cnt->x].x && pos.x < scene->map[cnt->y][cnt->x + 1].x)
		compare_h_to_small_obj(window, scene, cnt, pos);
	else if (scene->map[cnt->y][cnt->x].z >= 7 && pos.x > \
scene->map[cnt->y + 2][cnt->x].x && pos.x < scene->map[cnt->y][cnt->x + 2].x)
		compare_h_to_medium_obj(window, scene, pos, cnt);
}
