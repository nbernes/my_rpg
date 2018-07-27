/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** check malloc of the element of the scene
*/

#include <stdlib.h>
#include "proto.h"

int check_malloc_scene(scene_t *scene)
{
	if (scene->objs == NULL || scene->buttons == NULL ||	\
scene->text == NULL) {
		if (scene->objs != NULL)
			free(scene->objs);
		if (scene->buttons != NULL)
			free(scene->buttons);
		if (scene->text != NULL)
			free(scene->text);
		return (ERROR);
	}
	return (OK);
}
