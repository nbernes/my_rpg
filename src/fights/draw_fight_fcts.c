/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** draw functions
*/

#include "fight.h"

void draw_fighters(sfRenderWindow *window, fight_t *fgt, int life)
{
	sfSprite *potato = sfSprite_create();
	sfTexture *ttr;

	ttr = sfTexture_createFromFile("./ressource/badass_potato.png", \
NULL);
	print_life(window, life);
	sfSprite_setPosition(potato, (sfVector2f){300, 50});
	sfSprite_setTexture(potato, ttr, sfTrue);
	sfSprite_setScale(potato, (sfVector2f){0.7, 0.7});
	sfRenderWindow_drawSprite(window, potato, NULL);
	sfRenderWindow_drawSprite(window, fgt->ennemy->obj->sprite, NULL);
	sfSprite_destroy(potato);
	sfTexture_destroy(ttr);
}

void draw_fight(sfRenderWindow *window, menu_t *ptr, fight_t *fgt, int life)
{
	sfRenderWindow_drawSprite(window, fgt->background->sprite, NULL);
	sfRenderWindow_drawSprite(window, ptr->sprite, NULL);
	draw_fighters(window, fgt, life);
	draw_index(window, fgt->inst[0]);
	sfRenderWindow_drawText(window, ptr->options->t1, NULL);
	sfRenderWindow_drawText(window, ptr->options->t2, NULL);
	sfRenderWindow_drawText(window, ptr->options->t3, NULL);
	sfRenderWindow_drawText(window, ptr->options->t4, NULL);
	if (ptr->options->tq != NULL)
		sfRenderWindow_drawText(window, ptr->options->tq, NULL);
}
