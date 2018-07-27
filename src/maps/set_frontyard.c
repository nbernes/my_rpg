/*
** EPITECH PROJECT, 2018
** set_frontyard.c
** File description:
** ...
*/

#include "proto.h"

sfRenderWindow* set_picnic_table(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 170, 118};

	pos.y -= 30;
	pos.x -= 90;
	obj = create_object("./ressource/maps/garden/picnic.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_chips_bowl(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 60, 92};

	pos.y -= 15;
	pos.x -= 30;
	obj = create_object("./ressource/maps/garden/chips_bowl.png", \
pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_fence(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 60, 92};

	pos.y -= 30;
	pos.x -= 51;
	obj = create_object("./ressource/maps/garden/fence.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);

}

sfRenderWindow* set_human(sfRenderWindow* window, sfVector2f pos, \
char *pathway)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 150, 183};

	pos.y -= 95;
	pos.x -= 75;
	obj = create_object(pathway, pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}
