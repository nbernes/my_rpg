/*
** EPITECH PROJECT, 2018
** check_if_object.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"
#include "game_object.h"

sfRenderWindow *set_garden_objects(sfRenderWindow *window, sfVector2f pos, \
float value)
{
	switch ((int)value) {
	case 1:
	case 2:
	case 3:
		window = set_bush(window, pos,	(value - 1) * 41);
		break;
	case 4:
		window = set_pear(window, pos); break;
	case 6:
		window = set_trunk(window, pos); break;
	case 7:
		window = set_tree(window, pos); break;
	default:
		break;
	}
	return (window);
}

sfRenderWindow *set_frontyard_objects(sfRenderWindow *window, sfVector2f pos, \
float value)
{
	switch ((int)value) {
	case 1:
	case 2:
	case 3:
		window = set_bush(window, pos, (value - 1) * 41);
		break;
	case 4:
		window = set_chips_bowl(window, pos);
		break;
	case 5:
		window = set_fence(window, pos);
		break;
	case 7:
		window = set_picnic_table(window, pos);
		break;
	case 10:
		window = set_human(window, pos, "ressource/biglad.png");
	default: break;
	}
	return (window);
}

sfRenderWindow *set_pantry_objects(sfRenderWindow *window, sfVector2f pos, \
sfVector2i *cnt, float value)
{
	switch ((int)value) {
	case 1: if (cnt->y == 0)
			window = set_pantry_wall_r(window, pos);
		else
			window = set_pantry_wall_l(window, pos);

		break;
	case 2:	if (cnt->y == MAP_Y - 2)
			window = set_pantry_bot_l(window, pos);
		else
			window = set_pantry_bot_r(window, pos);
		break;
	case 3: window = set_boxes(window, pos); break;
	case 4: window = set_potato_bag(window, pos); break;
	case 5: window = set_shelf(window, pos); break;
	case 6: window = set_carrot(window, pos); break;
	case 7: window = set_fridge(window, pos); break;
	case 8: window = set_drawer(window, pos); break;
	case 10: window = set_dog(window, pos);
	}
	return (window);
}

sfRenderWindow *check_if_object(sfVector3f **map, sfRenderWindow *window, \
sfVector2i *cnt, type_stage_t *stage)
{
	sfVector2f pos;

	pos.y = map[cnt->y][cnt->x].y;
	pos.x = map[cnt->y][cnt->x].x;
	switch (*stage) {
	case PANTRY:
		window = set_pantry_objects(window, pos, cnt, \
map[cnt->y][cnt->x].z);
		break;
	case GARDEN:
		window = set_garden_objects(window, pos, map[cnt->y][cnt->x].z);
		break;
	case FRONTYARD:
		window = set_frontyard_objects(window, pos, \
map[cnt->y][cnt->x].z);
		break;
	case END:
		break;
	}
	return (window);
}
