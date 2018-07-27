/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** just display a simple scene
*/

#include <stdio.h>
#include "proto.h"

void verif_disp(scene_t *scene, int i, sfRenderWindow* window)
{
	if (scene->actor->inventory[i]->disp == 1 && \
scene->actor->inventory[i]->sprite != NULL)
		sfRenderWindow_drawSprite(window, \
scene->actor->inventory[i]->sprite, NULL);
}

void display_inventory(scene_t *scene, sfRenderWindow* window)
{
	if (scene->type == GAME && scene->actor->inventory != NULL) {
		for (int i = 0; scene->actor->inventory[i] != NULL; i++) {
			verif_disp(scene, i, window);
		}
	}
}

void display_other_things(scene_t *scen, sfRenderWindow* win)
{
	for (int i = 0; i < scen->nb_objects && scen->objs[i] != NULL; i++) {
		sfSprite_setPosition(scen->objs[i]->sprite, \
scen->objs[i]->position);
		if (scen->type == GAME && i != 2) {
			sfSprite_setTextureRect(scen->objs[i]->sprite, \
scen->objs[i]->rect);
			check_disp(scen, win, i);
		} else if (scen->type != GAME)
			sfRenderWindow_drawSprite(win, \
scen->objs[i]->sprite, NULL);
	}
	for (int i = 0; i < scen->nb_buttons; i++)
		sfRenderWindow_drawRectangleShape(win, \
scen->buttons[i]->rect, NULL);
	for (int i = 0; i < scen->nb_text; i++)
		if (scen->text[i]->disp == 1)
			sfRenderWindow_drawText(win, scen->text[i]->text, NULL);
	display_inventory(scen, win);
}

int next_display(scene_t *scene, type_scene_t actual, \
sfRenderWindow* window)
{
	if (scene[actual].type == GAME) {
		if (go_through_each_obst(window, \
scene[actual].objs[0]->position, &scene[actual]) == ERROR)
			return (ERROR);
		if (launch_fight(window, scene, actual) == ERROR)
			return (ERROR);
	}
	return (0);
}

int display(scene_t *scene, sfRenderWindow* window, type_scene_t actual)
{
	if (scene[actual].type == GAME) {
		if (create_map_caption(window, &scene[actual]) == ERROR)
			return (ERROR);
		sfSprite_setPosition(scene[actual].objs[2]->sprite,	\
scene[actual].objs[2]->position);
		sfSprite_setTextureRect(scene[actual].objs[2]->sprite, \
scene[actual].objs[2]->rect);
		sfRenderWindow_drawSprite(window, \
scene[actual].objs[2]->sprite, NULL);
		if (draw_caption(window) == ERROR)
			return (ERROR);
		window = draw_moving_sprites(scene[actual].map, window, \
scene[actual].stage, scene[actual].pnj);
		if (!window)
			return (ERROR);
	}
	display_other_things(&scene[actual], window);
	if (next_display(scene, actual, window) == ERROR)
		return (ERROR);
	return (OK);
}
