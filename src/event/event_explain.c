/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event explain
*/

#include "proto.h"

void event_explain(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	if (event->type == sfEvtMouseButtonReleased) {
		if (buttonisclicked(scenes[EXPLAIN].buttons[0], \
(sfVector2f){event->mouseButton.x, event->mouseButton.y}) == 1)
			scenes[EXPLAIN].buttons[0]->callback\
(window, scenes, actual, START);
	}
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			*actual = START;
}
