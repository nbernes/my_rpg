/*
** EPITECH PROJECT, 2017
** pg
** File description:
** music management
*/

#include "proto.h"

void start_music(scene_t *scene)
{
	if (sfMusic_getStatus(scene->music) == 2) {
		sfMusic_pause(scene->music);
		sfMusic_setLoop(scene->end, sfTrue);
		sfMusic_play(scene->end);
	}
}

void stop_music(scene_t *scene)
{
	if (sfMusic_getStatus(scene->end) == 2) {
		sfMusic_pause(scene->end);
		sfMusic_play(scene->music);
	}
}
