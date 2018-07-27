/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free fight menus functions
*/

#include "fight.h"

void free_sprite(sfSprite *ptr)
{
	if (!ptr)
		return;
	sfSprite_destroy(ptr);
}

void free_texture(sfTexture *ptr)
{
	if (!ptr)
		return;
	sfTexture_destroy(ptr);
}

void free_text(sfText *ptr)
{
	if (!ptr)
		sfText_destroy(ptr);
}

void free_font(sfFont *ptr)
{
	if (!ptr)
		return;
	sfFont_destroy(ptr);
}

void my_free(void *ptr)
{
	if (!ptr)
		return;
	free(ptr);
}
