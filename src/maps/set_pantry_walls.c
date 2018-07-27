/*
** EPITECH PROJECT, 2018
** set_lvng_room_objects.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* set_pantry_wall_l(sfRenderWindow *window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 200, 205};

	pos.y -= 86;
	pos.x -= 178;
	obj = create_object("./ressource/maps/pantry/wall_l.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_pantry_wall_r(sfRenderWindow *window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 200, 205};

	pos.y -= 75;
	pos.x -= 20;
	obj = create_object("./ressource/maps/pantry/wall_r.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_pantry_bot_r(sfRenderWindow *window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 200, 134};

	pos.y -= 10;
	pos.x -= 170;
	obj = create_object("./ressource/maps/pantry/bot_r.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_pantry_bot_l(sfRenderWindow *window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 200, 134};

	pos.y -= 4;
	pos.x -= 20;
	obj = create_object("./ressource/maps/pantry/bot_l.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}
