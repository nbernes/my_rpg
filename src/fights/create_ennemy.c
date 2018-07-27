/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create the ennemy
*/

#include "fight.h"

ennemy_t *set_dog_ennemy(ennemy_t *ptr)
{
	ptr->obj = malloc(sizeof(obj_t));

	if (ptr->obj == NULL)
		return (NULL);
	ptr->obj->sprite = sfSprite_create();
	ptr->obj->ttr = sfTexture_createFromFile("./ressource/\
angrydog_fight.png", NULL);
	sfSprite_setTexture(ptr->obj->sprite, ptr->obj->ttr, sfTrue);
	sfSprite_setPosition(ptr->obj->sprite, (sfVector2f){1000, 50});
	sfSprite_setScale(ptr->obj->sprite, (sfVector2f){6, 6});
	ptr->hp = 5;
	ptr->atk = 2;
	ptr->arm = 5;
	ptr->exp = 10;
	return (ptr);
}

ennemy_t *set_cat_ennemy(ennemy_t *ptr)
{
	ptr->obj = malloc(sizeof(obj_t));
	sfIntRect offset = {3, 42, 25, 22};

	if (ptr->obj == NULL)
		return (NULL);
	ptr->obj->sprite = sfSprite_create();
	ptr->obj->ttr = sfTexture_createFromFile("./ressource/\
ennemy_04.png", &offset);
	sfSprite_setTexture(ptr->obj->sprite, ptr->obj->ttr, sfTrue);
	sfSprite_setPosition(ptr->obj->sprite, (sfVector2f){1000, 130});
	sfSprite_setScale(ptr->obj->sprite, (sfVector2f){15, 15});
	ptr->hp = 9;
	ptr->atk = 4;
	ptr->arm = 2;
	ptr->exp = 25;
	return (ptr);
}

ennemy_t *set_human_ennemy(ennemy_t *ptr)
{
	ptr->obj = malloc(sizeof(obj_t));
	sfIntRect rect = {3, 18, 150, 150};

	if (ptr->obj == NULL)
		return (NULL);
	ptr->obj->sprite = sfSprite_create();
	ptr->obj->ttr = sfTexture_createFromFile("./ressource/\
angrylad.png", &rect);
	sfSprite_setTexture(ptr->obj->sprite, ptr->obj->ttr, sfTrue);
	sfSprite_setPosition(ptr->obj->sprite, (sfVector2f){900, 10});
	sfSprite_setScale(ptr->obj->sprite, (sfVector2f){3, 3});
	ptr->hp = 15;
	ptr->atk = 7;
	ptr->arm = 7;
	ptr->exp = 300;
	return (ptr);
}

ennemy_t *create_ennemy(int status)
{
	ennemy_t *ptr = malloc(sizeof(*ptr));

	if (!ptr || status > 2 || status < -1)
		return (NULL);
	switch (status) {
	case 0:	return (set_dog_ennemy(ptr));
	case 1:	return (set_cat_ennemy(ptr));
	case 2:	return (set_human_ennemy(ptr));
	}
	return (NULL);
}
