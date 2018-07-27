/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event credits
*/

#include "proto.h"

void event_credits(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	if (event->type == sfEvtMouseButtonReleased) {
		if (buttonisclicked(scenes[CREDITS].buttons[0], \
(sfVector2f){event->mouseButton.x, event->mouseButton.y}) == 1)
			scenes[CREDITS].buttons[0]->callback\
(window, scenes, actual, START);
	}
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			*actual = START;
}
