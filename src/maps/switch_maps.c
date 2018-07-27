/*
** EPITECH PROJECT, 2018
** switch_maps.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"

type_stage_t change_stage(float x, type_stage_t stage)
{
	if (x < WIN_WIDTH / 2)
		stage--;
	else
		stage++;
	return (stage);
}

int reset_flag(sfVector3f **map, sfVector2f pos)
{
	int flag = 0;
	sfVector2i i = {0, 0};

	pos.x += 16;
	pos.y += 32;
	flag = identify_which_tile(map, i, pos, MAP_X - 1);
	return (flag);
}

int switch_maps(sfVector3f **map, sfVector2f pos, type_stage_t stage, \
boolbis_t *enemies)
{
	pos.x += 16;
	pos.y += 32;
	if (identify_which_tile(map, (sfVector2i){0, 0}, pos, MAP_X - 1) == 0) {
		switch (stage) {
		case PANTRY:
			map = \
change_map(map, "ressource/maps/pantry/pantry.txt", stage, enemies); break;
		case GARDEN:
			map = \
change_map(map, "ressource/maps/garden/garden_1.txt", stage, enemies); break;
		case FRONTYARD:
			map = \
change_map(map, "ressource/maps/garden/garden_2.txt", stage, enemies); break;
		default: break;
		}
		if (map == NULL)
			return (ERROR);
		return (OK);
	}
	return (1);
}
