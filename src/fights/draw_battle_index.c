/*
** EPITECH PROJECT, 2018
** draw index of battle
** File description:
** alzkdaz
*/

#include "fight.h"

sfColor get_inst_color(int inst)
{
	switch (inst) {
	case 1:
		return (sfRed);
	case 2:
		return (sfCyan);
	case 3:
		return (sfGreen);
	default:
		return (sfWhite);
	}
}

void draw_index(sfRenderWindow *window, int select)
{
	obj_t tmp;
	sfIntRect crop = {0, 0, 97, 96};

	if (select == BASIC)
		return;
	else
		crop.left = 97 * (select - 1);
	tmp.sprite = sfSprite_create();
	tmp.ttr = sfTexture_createFromFile("./ressource/index.png", &crop);
	sfSprite_setTexture(tmp.sprite, tmp.ttr, sfTrue);
	sfSprite_setPosition(tmp.sprite, (sfVector2f){90, 510});
	sfRenderWindow_drawSprite(window, tmp.sprite, NULL);
	sfTexture_destroy(tmp.ttr);
	sfSprite_destroy(tmp.sprite);
}
