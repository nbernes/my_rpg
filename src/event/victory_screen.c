/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** file for victory screen related functs
*/

#include <stdio.h>
#include <stdbool.h>
#include "proto.h"

void move_rect_victory(scene_t *scene, int i, int moving)
{
	scene[GAME].objs[i]->rect.left += moving;
	sfSprite_setTextureRect(scene[GAME].objs[i]->sprite, \
scene[GAME].objs[i]->rect);
}

void display_victory_screen(sfRenderWindow *window, scene_t *scene, int pos)
{
	sfRenderWindow_drawSprite(window, scene[GAME].objs[pos]->sprite, NULL);
}

void manage_victory(sfRenderWindow* window, sfEvent *event, bool *end)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event->type == sfEvtKeyPressed && event->key.code == \
sfKeyEscape)
			*end = true;
	}
}

int manage_victory_time(sfClock *clock, scene_t *scene, int pos)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = sfTime_asSeconds(time);

	if (seconds > 4 && pos < 7) {
		if (pos < 4)
			move_rect_victory(scene, 10, 1600);
		else if (pos < 6)
			move_rect_victory(scene, 11, 1600 );
		pos++;
		sfClock_restart(clock);
	}
	return (pos);
}

void display_victory(scene_t *scene, sfRenderWindow *window, sfEvent *event)
{
	sfClock *clock = sfClock_create();
	bool end = false;
	int pos = 0;

	start_music(scene);
	while (end != true && sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		manage_victory(window, event, &end);
		pos = manage_victory_time(clock, scene, pos);
		if (pos < 3)
			display_victory_screen(window, scene, 10);
		else
			display_victory_screen(window, scene, 11);
		sfRenderWindow_display(window);
	}
	stop_music(scene);
}
