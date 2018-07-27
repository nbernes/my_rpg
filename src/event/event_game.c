/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** manage event game
*/

#include "proto.h"

void event_game(sfEvent *event, type_scene_t *actual, scene_t *scene)
{
	if (event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyEscape)
			*actual = PAUSE;
	}
	interface_event(scene, event);
}
