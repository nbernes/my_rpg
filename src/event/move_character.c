/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** move_character sprite
*/

#include "proto.h"
#include "scene.h"

void move_up(scene_t *scene)
{
	if (scene[GAME].objs[0]->rect.left < 64)
		scene[GAME].objs[0]->rect.left += 32;
	else
		scene[GAME].objs[0]->rect.left = 0;
	scene[GAME].objs[0]->rect.top = 96;
	test_character_moves(scene, -2, 0);
}

void move_down(scene_t *scene)
{
	if (scene[GAME].objs[0]->rect.left < 64)
		scene[GAME].objs[0]->rect.left += 32;
	else
		scene[GAME].objs[0]->rect.left = 0;
	scene[GAME].objs[0]->rect.top = 0;
	test_character_moves(scene, 2, 0);
}

void move_right(scene_t *scene)
{
	if (scene[GAME].objs[0]->rect.left < 64)
		scene[GAME].objs[0]->rect.left += 32;
	else
		scene[GAME].objs[0]->rect.left = 0;
	scene[GAME].objs[0]->rect.top = 64;
	test_character_moves(scene, 0, 2);
}

void move_left(scene_t *scene)
{
	if (scene[GAME].objs[0]->rect.left < 64)
		scene[GAME].objs[0]->rect.left += 32;
	else
		scene[GAME].objs[0]->rect.left = 0;
	scene[GAME].objs[0]->rect.top = 32;
	test_character_moves(scene, 0, -2);
}
