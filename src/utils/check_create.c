/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** check at start of the rpg
*/

#include <stdlib.h>
#include "proto.h"

int check_create(sfRenderWindow** window, scene_t **scenes)
{
	if (*window == NULL || *scenes == NULL) {
		if (*scenes != NULL)
			free(*scenes);
		if (*window != NULL)
			sfRenderWindow_destroy(*window);
		return (ERROR);
	}
	return (OK);
}
