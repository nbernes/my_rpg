/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** manage inventory and hero stat menu
*/

#include "proto.h"

void inventory_event(scene_t *scene, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyI && \
scene[GAME].objs[1]->disp == 0) {
		scene[GAME].objs[1]->disp = 1;
		scene[GAME].objs[8]->disp = 1;
		scene[GAME].objs[9]->disp = 1;
		if (scene[GAME].quest[0]->done == 0)
			scene[GAME].actor->inventory[0]->disp = 1;
		return;
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyI && \
scene[GAME].objs[1]->disp == 1) {
		scene[GAME].objs[1]->disp = 0;
		if (scene[GAME].actor->inventory[0] != NULL) {
			scene[GAME].actor->inventory[0]->disp = 0;
			scene[GAME].objs[8]->disp = 0;
			scene[GAME].objs[9]->disp = 0;
		}
		return;
	}
}

void hero_menu_event(scene_t *scene, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyH && \
scene[GAME].objs[6]->disp == 0) {
		scene[GAME].objs[6]->disp = 1;
		scene[GAME].text[6]->disp = 1;
		return;
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyH && \
scene[GAME].objs[6]->disp == 1) {
		scene[GAME].objs[6]->disp = 0;
		scene[GAME].text[6]->disp = 0;
		return;
	}
}

void hud_displaying_event(scene_t *scene, sfEvent *event)
{
	inventory_event(scene, event);
	hero_menu_event(scene, event);
}