/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
**  create text
*/

#include "proto.h"

void create_text(scene_t *scene, sfVector2f pos, int n, int disp)
{
	sfText_setString(scene->text[n]->text, "0");
	sfText_setOrigin(scene->text[n]->text, (sfVector2f){0, 0});
	sfText_setPosition(scene->text[n]->text, pos);
	scene->text[n]->disp = disp;
}

void create_hero_text(scene_t *scene)
{
	create_text(scene, (sfVector2f){71, 255}, 1, 1);
	create_text(scene, (sfVector2f){200, 296}, 2, 1);
	create_text(scene, (sfVector2f){200, 230}, 3, 1);
	create_text(scene, (sfVector2f){200, 263}, 4, 1);
	create_text(scene, (sfVector2f){72, 350}, 5, 1);
	create_text(scene, (sfVector2f){740, 20}, 6, 0);
	sfText_setCharacterSize(scene->text[1]->text, 35);
}