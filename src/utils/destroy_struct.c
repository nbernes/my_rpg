/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** destroy all the stucture
*/

#include "proto.h"

void destroy_struct(scene_t *scenes)
{
	if (scenes->music != NULL)
		sfMusic_destroy(scenes->music);
	if (scenes->end != NULL)
		sfMusic_destroy(scenes->end);
	if (scenes->fight != NULL)
		sfMusic_destroy(scenes->fight);
	if (scenes->game != NULL)
		sfClock_destroy(scenes->game);
	for (int i = 0; i < SCENE_SIZE; i++) {
		for (int y = 0; y < scenes[i].nb_objects; y++)
			destroy_object(scenes[i].objs[y]);
		for (int y = 0; y < scenes[i].nb_text; y++)
			sfFont_destroy(scenes[i].text[y]->font);
		for (int y = 0; y < scenes[i].nb_buttons; y++)
			sfRectangleShape_destroy(scenes[i].buttons[y]->rect);
	}
	if (scenes != NULL)
		free(scenes);
}
