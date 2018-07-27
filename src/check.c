/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** all check for launch game
*/

#include <stdbool.h>
#include "proto.h"

int check_status(bool *status, sfRenderWindow* window, sfEvent *event)
{
	if (*status == false) {
		if (start_game_explain(window, event) == ERROR)
			return (ERROR);
		*status = true;
	}
	return (0);
}

int check_actual(type_scene_t actual, bool *status, sfRenderWindow* window, \
sfEvent *event)
{
	if (actual == GAME) {
		if (check_status(status, window, event) == ERROR)
			return (ERROR);
		return (1);
	}
	return (0);
}
