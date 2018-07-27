/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage introduction
*/

#include <stdbool.h>
#include "proto.h"

void manage_introduction(sfRenderWindow* window, sfEvent *event, bool *end)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event->type == sfEvtMouseButtonReleased || \
event->type == sfEvtKeyReleased)
			*end = true;
	}
}
