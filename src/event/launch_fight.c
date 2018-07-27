/*
** EPITECH PROJECT, 2018
** launch_fight.c
** File description:
** ...
*/

#include "proto.h"

int evaluate_pantry_pos(sfRenderWindow* window, scene_t *scene, \
type_scene_t actual)
{
	int res = 0;
	sfVector2i i = {14, 2};

	if (identify_which_tile(scene[actual].map, i, \
scene[actual].objs[0]->position, 4) != 0 && scene[actual].map[3][15].z != 0) {
		if (sfMusic_getStatus(scene->music) == 2) {
			sfMusic_pause(scene->music);
			sfMusic_play(scene->fight);
		}
		res = fight(window, scene[actual].actor, PANTRY);
		if (sfMusic_getStatus(scene->fight) == 2) {
			sfMusic_pause(scene->fight);
			sfMusic_play(scene->music);
		}
		if (res == 1)
			scene[actual].map[3][15].z = 0;
	}
	return (res);
}

int manage_change_fight(int res, scene_t *scene, sfRenderWindow* window, \
type_scene_t actual)
{
	if (sfMusic_getStatus(scene->music) == 2) {
		sfMusic_pause(scene->music);
		sfMusic_play(scene->fight);
	}
	res = fight(window, scene[actual].actor, FRONTYARD);
	if (sfMusic_getStatus(scene->fight) == 2) {
		sfMusic_pause(scene->fight);
		sfMusic_play(scene->music);
	}
	if (res == 1)
		scene[actual].map[1][5].z = 0;
	return (res);
}

int evaluate_frontyard_pos(sfRenderWindow* window, scene_t *scene, \
type_scene_t actual)
{
	int res = 0;
	sfVector2i i = {9, 0};
	sfVector2f pos;

	if (identify_which_tile(scene[actual].map, i, \
scene[actual].objs[0]->position, 4) != 0 && scene[actual].map[1][5].z != 0) {
		res = manage_change_fight(res, scene, window, actual);
	} else if (identify_which_tile(scene[actual].map, i,	\
scene[actual].objs[0]->position, 5) != 0 && \
scene[actual].enemies.frontyard == true) {
		pos = project_iso_point(5 * SCALING_X, 1 * SCALING_Y);
		window = set_human(window, pos, "ressource/angrylad.png");
		if (!window)
			return (ERROR);
	}
	return (res);
}

int manage_res(int res, sfRenderWindow* window, type_scene_t actual, \
scene_t *scene)
{
	if (res == 1) {
		if (manage_flag(window, &scene[actual]) == ERROR)
			return (ERROR);
		if (scene[actual].stage == PANTRY)
			scene[actual].enemies.pantry = false;
		if (scene[actual].stage == FRONTYARD)
			scene[actual].enemies.frontyard = false;
	} else if (res == -1) {
		if (sfMusic_getStatus(scene->fight) == 2) {
			sfMusic_pause(scene->fight);
			sfMusic_pause(scene->music);
		}
		end(window, scene);
	}
	return (0);
}

int launch_fight(sfRenderWindow* window, scene_t *scene, type_scene_t actual)
{
	int res = 0;

	if (scene[actual].type == GAME) {
		switch (scene[actual].stage) {
		case PANTRY: res = evaluate_pantry_pos(window, scene, actual); \
			break;
		case FRONTYARD: \
res = evaluate_frontyard_pos(window, scene, actual); break;
		default: break;
		}
	}
	if (manage_res(res, window, actual, scene) == ERROR)
		return (ERROR);
	return (res);
}
