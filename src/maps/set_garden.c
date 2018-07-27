/*
** EPITECH PROJECT, 2018
** set_garden_objects.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* set_trunk(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 40, 42};

	pos.y -= 17;
	pos.x -= 25;
	obj = create_object("./ressource/maps/garden/trunk.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_bush(sfRenderWindow* window, sfVector2f pos, int bush_x)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {bush_x, 0, 41, 40};

	pos.y -= 13;
	pos.x -= 20;
	obj = create_object("./ressource/maps/garden/Bushes.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_tree(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 300, 360};

	pos.y -= 290;
	pos.x -= 155;
	obj = create_object("./ressource/maps/garden/tree.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}
