/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare all sprite of the introduction
*/

#include "proto.h"

game_object_t *prepare_potato(void)
{
	game_object_t *potato = malloc(sizeof(*potato));

	if (potato == NULL)
		return (NULL);
	potato->texture = sfTexture_createFromFile("ressource/\
character01.png", NULL);
	potato->sprite = sfSprite_create();
	if (potato->texture == NULL || potato->sprite == NULL)
		return (NULL);
	sfSprite_setTexture(potato->sprite, potato->texture, sfTrue);
	potato->position = (sfVector2f){500, 500};
	potato->rect = (sfIntRect){0, 64, 32, 32};
	sfSprite_setPosition(potato->sprite, potato->position);
	sfSprite_setTextureRect(potato->sprite, potato->rect);
	return (potato);
}

game_object_t *prepare_carrot(void)
{
	game_object_t *carrot = malloc(sizeof(*carrot));

	if (carrot == NULL)
		return (NULL);
	carrot->texture = sfTexture_createFromFile("ressource/\
character02.png", NULL);
	carrot->sprite = sfSprite_create();
	if (carrot->texture == NULL || carrot->sprite == NULL)
		return (NULL);
	sfSprite_setTexture(carrot->sprite, carrot->texture, sfTrue);
	carrot->position = (sfVector2f){530, 625};
	carrot->rect = (sfIntRect){0, 80, 40, 40};
	sfSprite_setPosition(carrot->sprite, carrot->position);
	sfSprite_setTextureRect(carrot->sprite, carrot->rect);
	return (carrot);
}

game_object_t *prepare_ant(void)
{
	game_object_t *ant = malloc(sizeof(*ant));

	if (ant == NULL)
		return (NULL);
	ant->texture = sfTexture_createFromFile("ressource/\
Ennemy_01.png", NULL);
	ant->sprite = sfSprite_create();
	if (ant->texture == NULL || ant->sprite == NULL)
		return (NULL);
	sfSprite_setTexture(ant->sprite, ant->texture, sfTrue);
	ant->position = (sfVector2f){600, 525};
	ant->rect = (sfIntRect){0, 128, 64, 64};
	sfSprite_setPosition(ant->sprite, ant->position);
	sfSprite_setTextureRect(ant->sprite, ant->rect);
	return (ant);
}
