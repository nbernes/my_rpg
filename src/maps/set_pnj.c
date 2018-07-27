/*
** EPITECH PROJECT, 2018
** set_pnj.c
** File description:
** ...
*/

#include "proto.h"

int update_from_clock(sfClock *clock, int left)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = sfTime_asSeconds(time);

	if (seconds > 0.2) {
		if (left >= 2)
			left = 0;
		else
			left++;
		sfClock_restart(clock);
	}
	return (left);
}

sfRenderWindow* set_mushroom(sfRenderWindow* window, sfVector2f pos, \
sfClock *clock)
{
	static int left = 0;
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 78, 79};

	left = update_from_clock(clock, left);
	rect.left = left * 75;
	pos.y -= 55;
	pos.x -= 35;
	obj = create_object("./ressource/pnj_02_animated.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_pear(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 120, 130};

	pos.y -= 90;
	pos.x -= 51;
	obj = create_object("./ressource/pnj_01.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}

sfRenderWindow* set_carrot(sfRenderWindow* window, sfVector2f pos)
{
	game_object_t *obj = malloc(sizeof(game_object_t *));
	sfIntRect rect = {0, 0, 40, 39};

	pos.y -= 22;
	pos.x -= 22;
	obj = create_object("./ressource/character02.png", pos, rect, 1);
	if (!obj)
		return (NULL);
	sfSprite_setPosition(obj->sprite, pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window, obj->sprite, NULL);
	destroy_object(obj);
	return (window);
}
