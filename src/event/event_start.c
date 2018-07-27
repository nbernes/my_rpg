/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event start
*/

#include "proto.h"

void other_event_start(sfRenderWindow* window, sfVector2f click, \
scene_t *scenes, type_scene_t *actual)
{
	if (buttonisclicked(scenes[START].buttons[2], click) == 1)
		scenes[START].buttons[0]->callback(window, scenes, actual, \
CREDITS);
	if (buttonisclicked(scenes[START].buttons[3], click) == 1)
		scenes[START].buttons[0]->callback(window, scenes, actual, \
EXPLAIN);
	if (buttonisclicked(scenes[START].buttons[4], click) == 1)
		sfRenderWindow_close(window);
}

void event_start(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	sfVector2f click;

	if (event->type == sfEvtMouseButtonReleased) {
		click.x = event->mouseButton.x;
		click.y = event->mouseButton.y;
		if (buttonisclicked(scenes[START].buttons[0], click) == 1)
			scenes[START].buttons[0]->callback(window, scenes, \
actual, GAME);
		if (buttonisclicked(scenes[START].buttons[1], click) == 1)
			scenes[START].buttons[0]->callback(window, scenes, \
actual, PARAMETERS);
		other_event_start(window, click, scenes, actual);
	}
}
