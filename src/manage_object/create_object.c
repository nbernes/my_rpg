/*
** EPITECH PROJECT, 2017
** create_object
** File description:
** create_object
*/

#include <stdlib.h>
#include "proto.h"

game_object_t *create_object(const char *path_to_spritesheet, \
sfVector2f pos, sfIntRect rect, int disp)
{
	game_object_t *object = malloc(sizeof(*object));

	if (object == NULL)
		return (NULL);
	object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	if (object->texture == NULL)
		return (NULL);
	object->sprite = sfSprite_create();
	if (object->sprite == NULL)
		return (NULL);
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->position = pos;
	object->rect = rect;
	object->disp = disp;
	return (object);
}
