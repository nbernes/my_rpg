/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** handle interface and hud event
*/

#include <stdio.h>
#include <string.h>
#include "proto.h"

int check_quest_event(scene_t *scene, sfEvent *event)
{
	check_event_search(scene, event);
	check_pnj_talks(scene, event);
	if (scene[GAME].quest[0]->ongoing == 1 && scene[GAME].quest[0]->\
items_required == 1 && event->type == sfEvtKeyPressed && event->key.code \
== sfKeyF && scene[GAME].objs[0]->position.x > 510 && scene[GAME].objs[0]->\
position.x < 568 && scene[GAME].objs[0]->position.y > 515 && scene[GAME].objs\
[0]->position.y < 600 && scene[GAME].stage == GARDEN) {
		scene[GAME].quest[0]->ongoing = 0;
		scene[GAME].actor->xp += scene[GAME].quest[0]->xp;
		scene[GAME].quest[0]->done = 1;
		scene[GAME].text[0]->disp = 0;
		scene[GAME].objs[4]->disp = 0;
		scene[GAME].text[8]->disp = 1;
		scene[GAME].actor->inventory[0]->disp = 0;
		move_rect(scene, 138 , 9);
		scene[GAME].actor->def += 5;
		return (1);
	}
	return (0);
}

void check_pnj_event(scene_t *scene, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyF && \
scene[GAME].objs[0]->position.x > 780 && scene[GAME].objs[0]->position.x < 820 \
&& scene[GAME].objs[0]->position.y > 375 && scene[GAME].objs[0]->position.y \
< 430 && scene[GAME].stage == GARDEN && scene[GAME].quest[0]->ongoing == 1) {
		scene[GAME].objs[4]->disp = 0;
		scene[GAME].quest[0]->items_required = 1;
		scene[GAME].actor->inventory[0] = scene[GAME].objs[4];
		if (scene[GAME].objs[1]->disp == 1)
			scene[GAME].actor->inventory[0]->disp = 1;
		scene[GAME].actor->inventory[0]->position.x = 1160;
		scene[GAME].actor->inventory[0]->position.y = 150;
		if (scene[GAME].quest[0]->done == 1)
			scene[GAME].objs[4]->disp = 1;
	}
}

void upgrade_event(scene_t *scene, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyJ && \
scene[GAME].objs[6]->disp == 1 && scene[GAME].actor->skill_point > 0) {
		scene[GAME].actor->atk += 2;
		scene[GAME].actor->skill_point -= 1;
		return;
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyK && \
scene[GAME].objs[6]->disp == 1 && scene[GAME].actor->skill_point > 0) {
		scene[GAME].actor->def += 1;
		scene[GAME].actor->skill_point -= 1;
		return;
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyL && \
scene[GAME].objs[6]->disp == 1 && scene[GAME].actor->skill_point > 0) {
		scene[GAME].actor->hp += 5;
		scene[GAME].actor->skill_point -= 1;
		return;
	}
}

void stat_event(scene_t *scene, sfEvent *event)
{
	upgrade_event(scene, event);
	if (scene[GAME].actor->skill_point == 0 && event->type == \
sfEvtKeyPressed && (event->key.code == sfKeyK || event->key.code == sfKeyJ \
|| event->key.code == sfKeyL) && scene[GAME].objs[6]->disp == 1)
		scene[GAME].objs[7]->disp = 1;
}

void interface_event(scene_t *scene, sfEvent *event)
{
	hud_displaying_event(scene, event);
	check_pnj_event(scene, event);
	if (check_quest_event(scene, event) == 1)
		return;
	if (scene[GAME].quest[0]->done == 0 && event->type == sfEvtKeyPressed \
&& event->key.code == sfKeyF && scene[GAME].objs[0]->position.x > 490 && \
scene[GAME].objs[0]->position.x < 580 && scene[GAME].objs[0]->position.y > 550 \
&& scene[GAME].objs[0]->position.y < 600 && scene[GAME].stage == GARDEN) {
		scene[GAME].quest[0]->ongoing = 1;
		scene[GAME].objs[4]->disp = 1;
		scene[GAME].text[0]->disp = 1;
	}
	stat_event(scene, event);
}
