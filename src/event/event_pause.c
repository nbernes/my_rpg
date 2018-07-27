/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event pause
*/

#include "proto.h"

void event_pause(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	sfVector2f click;

	if (event->type == sfEvtMouseButtonReleased) {
		click.x = event->mouseButton.x;
		click.y = event->mouseButton.y;
		if (buttonisclicked(scenes[PAUSE].buttons[0], click) == 1)
			scenes[PAUSE].buttons[0]->callback\
(window, scenes, actual, GAME);
		if (buttonisclicked(scenes[PAUSE].buttons[1], click) == 1)
			scenes[PAUSE].buttons[1]->callback\
(window, scenes, actual, START);
		if (buttonisclicked(scenes[PAUSE].buttons[2], click) == 1)
			sfRenderWindow_close(window);
	}
}
