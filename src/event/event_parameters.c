/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event parameters
*/

#include "proto.h"

void manage_music(scene_t *scenes)
{
	if (sfMusic_getStatus(scenes->music) == 2) {
		sfMusic_pause(scenes->music);
	} else if (sfMusic_getStatus(scenes->music) != 2) {
		sfMusic_play(scenes->music);
	}
}

void event_parameters(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	sfVector2i mouse = sfMouse_getPosition(NULL);
	sfVector2i tmp = sfRenderWindow_getPosition(window);

	if (event->type == sfEvtMouseButtonReleased) {
		tmp.x = mouse.x - tmp.x;
		tmp.y = (mouse.y - tmp.y) - 30;
		if ((tmp.x >= 580 && tmp.x <= 780) && \
(tmp.y >= 425 && tmp.y <= 500))
			manage_music(scenes);
		if ((tmp.x >= 30 && tmp.x <= 230) && \
(tmp.y >= 30 && tmp.y <= 110))
			*actual = START;
	}
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			*actual = START;
}
