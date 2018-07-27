/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** test character moves
*/

#include "proto.h"

void test_character_moves(scene_t *scene, \
float incr_y, float incr_x)
{
	scene[GAME].objs[0]->position.x += incr_x + 16;
	scene[GAME].objs[0]->position.y += incr_y + 32;
	if (get_obj_boundaries(scene[GAME].map, \
scene[GAME].objs[0]->position, scene[GAME].stage) == 0) {
		scene[GAME].objs[0]->position.x -= 16;
		scene[GAME].objs[0]->position.y -= 32;
	} else {
		scene[GAME].objs[0]->position.x -= (incr_x + 16);
		scene[GAME].objs[0]->position.y -= (incr_y + 32);
	}
}
