/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare scene parameters
*/

#include <stdlib.h>
#include "proto.h"

int manage_objects_parameters(scene_t *parameters_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	parameters_scene->objs[0] = create_object("ressource/Menu_params.png", \
pos, rect, 1);
	if (parameters_scene->objs[0] == NULL)
		return (ERROR);
	return (OK);
}

int prepare_parameters(scene_t *parameters_scene)
{
	if (parameters_scene == NULL)
		return (ERROR);
	parameters_scene->nb_objects = 1;
	parameters_scene->objs = malloc(sizeof(game_object_t *) * \
parameters_scene->nb_objects);
	parameters_scene->nb_buttons = 0;
	parameters_scene->buttons = malloc(sizeof(button_t *) * \
parameters_scene->nb_buttons);
	parameters_scene->nb_text = 0;
	parameters_scene->text = malloc(sizeof(text_t *) * \
parameters_scene->nb_text);
	parameters_scene->type = PARAMETERS;
	if (check_malloc_scene(parameters_scene) == ERROR || \
manage_objects_parameters(parameters_scene) == ERROR)
		return (ERROR);
	return (OK);
}
