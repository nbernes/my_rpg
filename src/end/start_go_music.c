/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** start end music
*/

#include "end.h"
#include "proto.h"

sfMusic *start_go_music(scene_t *scene)
{
	sfMusic *music;

	if (sfMusic_getStatus(scene->music) != 2 && \
sfMusic_getStatus(scene->fight) != 2)
		return (NULL);
	sfMusic_stop(scene->music);
	music = sfMusic_createFromFile("./ressource/go_music.ogg");
	sfMusic_setVolume(music, 50);
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
	return (music);
}

void free_music(sfMusic *music)
{
	if (music == NULL)
		return;
	sfMusic_destroy(music);
}
