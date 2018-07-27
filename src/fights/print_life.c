/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** print life
*/

#include "fight.h"

void print_life(sfRenderWindow *window, int life)
{
	char *s = int_to_str(life);
	sfText *hp;
	sfFont *font;

	if (s == NULL)
		return;
	hp = sfText_create();
	font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(hp, font);
	sfText_setString(hp, s);
	sfText_setScale(hp, (sfVector2f){2, 2});
	sfText_setPosition(hp, (sfVector2f){400, 520});
	sfText_setColor(hp, sfRed);
	sfRenderWindow_drawText(window, hp, NULL);
	sfText_destroy(hp);
	sfFont_destroy(font);
	my_free(s);
}
