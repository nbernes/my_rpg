/*
** EPITECH PROJECT, 2018
** set_other_pantryobjects.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* set_drawer(sfRenderWindow* window, sfVector2f pos)
{
	static int cnt = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 50, 72};

	pos.y -= 40;
	pos.x -= 25;
	obj = create_object("./ressource/maps/pantry/drawer.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfSprite_setRotation(obj->sprite, 2.20);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	cnt++;
	return (window);
}
