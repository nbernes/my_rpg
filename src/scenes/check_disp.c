/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** just display a simple scene
*/

#include <stdio.h>
#include "proto.h"

void check_disp(scene_t *scene, sfRenderWindow* window, int i)
{
	if (scene->objs[i]->disp == 1)
		sfRenderWindow_drawSprite(window, scene->objs[i]->sprite, NULL);
}
