/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare all scenes
*/

#include "proto.h"

int prepare_scenes(scene_t *scenes)
{
	if (prepare_start(&scenes[0]) == ERROR)
		return (ERROR);
	if (prepare_pause(&scenes[1]) == ERROR)
		return (ERROR);
	if (prepare_credits(&scenes[2]) == ERROR)
		return (ERROR);
	if (prepare_explain(&scenes[3]) == ERROR)
		return (ERROR);
	if (prepare_parameters(&scenes[4]) == ERROR)
		return (ERROR);
	if (prepare_game(&scenes[5]) == ERROR)
		return (ERROR);
	if (prepare_win(&scenes[6]) == ERROR)
		return (ERROR);
	if (prepare_lose(&scenes[7]) == ERROR)
		return (ERROR);
	return (OK);
}
