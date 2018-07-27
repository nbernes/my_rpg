/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** check event linked to quest
*/

#include <stdio.h>
#include "proto.h"

void move_rect(scene_t *scene, int moving, int i)
{
	scene[GAME].objs[i]->rect.left = moving;
}

void check_pnj_talks(scene_t *scene, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code \
== sfKeyF && scene[GAME].objs[0]->position.x > 614 && scene[GAME].objs[0]->\
position.x < 670 && scene[GAME].objs[0]->position.y > 505 && scene[GAME].objs\
[0]->position.y < 560 && scene[GAME].stage == PANTRY) {
		scene[GAME].text[11]->disp = 0;
		scene[GAME].text[9]->disp = 1;
	}
	if (event->type == sfEvtKeyPressed && event->key.code \
== sfKeyF && scene[GAME].objs[0]->position.x > 440 && scene[GAME].objs[0]->\
position.x < 525 && scene[GAME].objs[0]->position.y > 500 && scene[GAME].objs\
[0]->position.y < 560 && scene[GAME].stage == FRONTYARD) {
		scene[GAME].text[10]->disp = 1;
	}
}

void check_event_search(scene_t *scene, sfEvent *event)
{
	static int ongoing = 0;

	if (event->type == sfEvtKeyPressed && event->key.code \
== sfKeyF && scene[GAME].objs[0]->position.x > 810 && scene[GAME].objs[0]->\
position.x < 900 && scene[GAME].objs[0]->position.y > 700 && scene[GAME].objs\
[0]->position.y < 800 && ongoing == 0 && scene[GAME].stage == GARDEN) {
		scene[GAME].actor->xp += 50;
		if (scene[GAME].text[0]->disp == 1)
			scene[GAME].text[0]->disp = 0;
		if (scene[GAME].text[8]->disp == 1)
			scene[GAME].text[8]->disp = 0;
		scene[GAME].text[7]->disp = 1;
		move_rect(scene, 34, 8);
		ongoing = 1;
		scene[GAME].actor->atk += 5;
	}
}
