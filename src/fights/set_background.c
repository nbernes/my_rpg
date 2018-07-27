/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set background
*/

#include "fight.h"

obj_t *set_background(int status)
{
	obj_t *obj = malloc(sizeof(*obj));

	if (obj == NULL)
		return (NULL);
	obj->sprite = sfSprite_create();
	if (status < 0 || status > 2)
		return (NULL);
	switch (status) {
	case 0:	obj->ttr = sfTexture_createFromFile("./ressource/\
bg_pantry.png", NULL); break;
	case 1:	obj->ttr = sfTexture_createFromFile("./ressource/\
bg_garden.png", NULL);	break;
	case 2:	obj->ttr = sfTexture_createFromFile("./ressource/\
bg_garden.png", NULL);	break;
	default: break;
	}
	sfSprite_setTexture(obj->sprite, obj->ttr, sfTrue);
	return (obj);
}
