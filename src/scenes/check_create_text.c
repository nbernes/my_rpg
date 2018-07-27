/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** check create of the text
*/

#include "proto.h"

int check_create_text(int i, scene_t *start_scene)
{
	start_scene->text[i]->text = sfText_create();
	if (start_scene->text[i]->font == NULL ||	\
start_scene->text[i]->text == NULL)
		return (ERROR);
	return (OK);
}
