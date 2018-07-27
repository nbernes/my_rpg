/*
** EPITECH PROJECT, 2018
** check_if_obst.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"

int check_if_obst(sfVector3f **map, sfVector2f pos, type_stage_t stage)
{
	sfVector2i cnt;
	int flag = 0;

	for (cnt.y = 0; cnt.y < MAP_Y - 1&& flag == 0; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X - 1 && flag == 0; cnt.x++)
			flag += identify_obst_size(map, cnt, pos, stage);
	}
	if (flag > 1)
		return (ERROR);
	return (flag);
}

int calc_exit_bounds(sfVector3f **map, sfVector2f pos)
{
	int flag = 0;
	sfVector2i exit_bounds = {17, 10};

	for (; exit_bounds.y > 6; exit_bounds.y--)
		flag += identify_which_tile(map, exit_bounds, pos, 2);
	return (flag);
}

int manage_pantry_bounds(sfVector3f **map, sfVector2f pos, type_stage_t stage)
{
	sfVector2i map_bounds = {1, 1};
	int flag = 0;

	if (calc_exit_bounds(map, pos) == 0 && identify_which_tile(map,	\
map_bounds, pos, MAP_X - 3) == 0)
		return (ERROR);
	else
		flag = check_if_obst(map, pos, stage);
	return (flag);
}

int get_obj_boundaries(sfVector3f **map, sfVector2f pos, \
type_stage_t stage)
{
	int flag = 0;

	switch (stage) {
	case PANTRY:
		flag = manage_pantry_bounds(map, pos, stage);
		break;
	case GARDEN:
	case FRONTYARD:
		flag = check_if_obst(map, pos, stage);
		break;
	default:
		break;
	}
	return (flag);
}
