/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare gameplay with initialisation
*/

#include <time.h>
#include <stdlib.h>
#include "proto.h"

int prepare_music(scene_t *scenes)
{
	scenes->music = sfMusic_createFromFile("ressource/music.ogg");
	scenes->fight = sfMusic_createFromFile("ressource/potatoes_boss_\
fight.ogg");
	scenes->end = sfMusic_createFromFile("ressource/sans_titre.ogg");
	if (scenes->music == NULL || scenes->fight == NULL || \
scenes->end == NULL)
		return (ERROR);
	sfMusic_setLoop(scenes->music, sfTrue);
	sfMusic_setLoop(scenes->fight, sfTrue);
	sfMusic_setLoop(scenes->end, sfTrue);
	sfMusic_play(scenes->music);
	return (0);
}

int prepare_gameplay(void)
{
	sfRenderWindow* window = create_window();
	scene_t *scenes = malloc(sizeof(scene_t) * SCENE_SIZE);

	srand(time(NULL));
	if (check_create(&window, &scenes) == ERROR)
		return (ERROR);
	if (prepare_music(scenes) == ERROR)
		return (ERROR);
	if (prepare_scenes(scenes) == ERROR)
		return (ERROR);
	scenes->game = sfClock_create();
	if (scenes->game == NULL || launch_game(window, scenes) == ERROR) {
		destroy_struct(scenes);
		return (ERROR);
	}
	destroy_struct(scenes);
	sfRenderWindow_destroy(window);
	return (OK);
}
