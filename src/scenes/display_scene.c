/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** display_scene
*/

#include "proto.h"

void display_other_scene(sfRenderWindow* window, scene_t *scenes, \
type_scene_t *actual)
{
	for (int i = 0; i < scenes[*actual].nb_buttons; i++)
		sfRenderWindow_drawRectangleShape(window, \
scenes[*actual].buttons[i]->rect, NULL);
	for (int i = 0; i < scenes[*actual].nb_text; i++) {
		if (scenes[*actual].text[i]->disp == 1)
			sfRenderWindow_drawText(window, \
scenes[*actual].text[i]->text, NULL);
	}
}

void check_actual_game(sfRenderWindow* window, scene_t *scenes, \
type_scene_t *actual)
{
	if (*actual == GAME) {
		sfSprite_setPosition(scenes[*actual].objs[2]->sprite, \
scenes[*actual].objs[2]->position);
		sfSprite_setTextureRect(scenes[*actual].objs[2]->sprite, \
scenes[*actual].objs[2]->rect);
		sfRenderWindow_drawSprite(window, \
scenes[*actual].objs[2]->sprite, NULL);
	}

}

void display_scene(sfRenderWindow* window, scene_t *scenes, \
type_scene_t *actual, type_scene_t change_by)
{
	check_actual_game(window, scenes, actual);
	*actual = change_by;
	for (int i = 0; i < scenes[*actual].nb_objects; i++) {
		sfSprite_setPosition(scenes[*actual].objs[i]->sprite, \
scenes[*actual].objs[i]->position);
		if (*actual == GAME && i != 2) {
			sfSprite_setTextureRect(scenes[*actual].objs[i]\
->sprite, scenes[*actual].objs[i]->rect);
			check_disp(&scenes[*actual], window, i);
		} else if (*actual != GAME)
			sfRenderWindow_drawSprite(window, \
scenes[*actual].objs[i]->sprite, NULL);
	}
	display_other_scene(window, scenes, actual);
}
