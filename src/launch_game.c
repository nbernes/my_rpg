/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** launch game
*/

#include <time.h>
#include <stdbool.h>
#include "proto.h"

void update_timer(sfClock *clock, scene_t *scene)
{
	sfTime time;
	float seconds;

	time = sfClock_getElapsedTime(clock);
	seconds = sfTime_asSeconds(time);
	if (seconds > 15) {
		scene[GAME].text[8]->disp = 0;
		sfClock_restart(clock);
		return;
	}
	if (seconds > 5) {
		scene[GAME].objs[7]->disp = 0;
		scene[GAME].text[7]->disp = 0;
		if (scene[GAME].stage != PANTRY) {
			scene[GAME].text[11]->disp = 0;
			scene[GAME].text[9]->disp = 0;
		}
		sfClock_restart(clock);
		return;
	}
}

void move_background(int offset, int max_value, game_object_t *object)
{
	if (object->rect.left < max_value)
		object->rect.left += offset;
	else
		object->rect.left = 0;
}

int manage_value(scene_t *scenes, type_scene_t actual, sfRenderWindow* window, \
sfEvent *event)
{
	static bool status = false;
	int value = 0;

	value = check_actual(actual, &status, window, event);
	if (value == ERROR)
		return (ERROR);
	else if (value == 1) {
		move_background(1, 1600, scenes[actual].objs[2]);
		if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
			move_left(scenes);
		if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
			move_right(scenes);
		if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
			move_up(scenes);
		if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
			move_down(scenes);
	}
	return (0);
}

int verif_actual(scene_t *scenes, type_scene_t actual, sfRenderWindow* window,
sfEvent *event)
{
	if (actual == GAME && scenes[actual].stage == END) {
		display_victory(scenes, window, event);
		return (1);
	}
	return (0);
}

int launch_game(sfRenderWindow* window, scene_t *scenes)
{
	sfEvent event;
	type_scene_t actual = START;
	sfClock *clock = sfClock_create();
	particles_t *part = init_particles_leaf("ressource/leaf.png");

	if (clock == NULL || part == NULL || play_int(window, &event) == ERROR)
		return (ERROR);
	while (sfRenderWindow_isOpen(window)) {
		if (analyse_event(window, &event, scenes, &actual) == ERROR)
			return (ERROR);
		if (manage_value(scenes, actual, window, &event) == ERROR)
			return (ERROR);
		update_timer(clock, scenes);
		if (actual == GAME && scenes[actual].stage == GARDEN)
			draw_particles_leaf(window, part);
		if (verif_actual(scenes, actual, window, &event) == 1)
			break;
		sfRenderWindow_display(window);
	}
	free_game_data(part, clock);
	return (OK);
}
