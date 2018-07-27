/*
** EPITECH PROJECT, 2018
** set_pantry_objects.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* set_fridge(sfRenderWindow* window, sfVector2f pos)
{
	static int cnt = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 70, 125};

	pos.y -= 70;
	pos.x -= 25;
	obj = create_object("./ressource/maps/pantry/fridge.png", pos, rect, 1);
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

sfRenderWindow* set_shelf(sfRenderWindow* window, sfVector2f pos)
{
	static int cnt = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 59, 97};

	pos.y -= 40;
	pos.x -= 50;
	obj = create_object("./ressource/maps/pantry/shelf.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	cnt++;
	return (window);
}

sfRenderWindow* set_potato_bag(sfRenderWindow* window, sfVector2f pos)
{
	static int cnt = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 60, 67};

	pos.y -= 40;
	pos.x -= 35;
	obj = create_object("./ressource/maps/pantry/potato_bag.png", \
pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	cnt++;
	return (window);
}

sfRenderWindow* set_boxes(sfRenderWindow* window, sfVector2f pos)
{
	static int cnt = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 76, 60};

	if (cnt > 4) {
		cnt = 0;
		rect.left = 76;
	}
	pos.y -= 30;
	pos.x -= 35;
	obj = create_object("./ressource/maps/pantry/boxes.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfSprite_setRotation(obj->sprite, 3);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	cnt++;
	return (window);
}

sfRenderWindow* set_dog(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 60, 63};

	pos.y -= 45;
	pos.x -= 30;
	obj = create_object("./ressource/angrydog.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}
