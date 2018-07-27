/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** display all the introduciton
*/

#include "proto.h"

int display_introduction(sfRenderWindow* window, game_object_t **all_sprites)
{
	sfFont* font = sfFont_createFromFile("ressource/caviar.ttf");
	sfText* text = sfText_create();
	static sfVector2f pos = {1700, 100};

	if (pos.x > -(WIN_WIDTH))
		pos.x -= 5;
	else
		return (1);
	if (verify_creation_of_text(&font, &text) == ERROR)
		return (ERROR);
	sfText_setString(text, "Potato's Escape");
	sfText_setFont(text, font);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 200);
	sfRenderWindow_drawText(window, text, NULL);
	for (int i = 0; all_sprites[i] != NULL; i++)
		sfRenderWindow_drawSprite(window, all_sprites[i]->sprite, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
	return (OK);
}
