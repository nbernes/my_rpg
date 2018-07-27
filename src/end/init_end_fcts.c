/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init end fcts
*/

#include "end.h"

obj_t *init_game_over_object(void)
{
	obj_t *ptr = malloc(sizeof(obj_t));

	if (!ptr)
		return (NULL);
	ptr->sprite = sfSprite_create();
	ptr->ttr = sfTexture_createFromFile("./ressource/\
game_over.png", NULL);
	if (!ptr->sprite || !ptr->ttr) {
		free_sprite(ptr->sprite);
		free_texture(ptr->ttr);
		my_free(ptr);
		return (NULL);
	}
	sfSprite_setTexture(ptr->sprite, ptr->ttr, sfTrue);
	return (ptr);
}

parallax_t *set_game_over(void)
{
	parallax_t *ptr = malloc(sizeof(parallax_t));

	if (ptr == NULL)
		return (NULL);
	ptr->obj = init_game_over_object();
	if (!ptr->obj) {
		my_free(ptr);
		return (NULL);
	}
	ptr->pos.x = 0;
	ptr->pos.y = -900;
	return (ptr);
}

obj_t *init_parallax_object(void)
{
	obj_t *ptr = malloc(sizeof(obj_t));

	if (!ptr)
		return (NULL);
	ptr->sprite = sfSprite_create();
	ptr->ttr = sfTexture_createFromFile("./ressource/\
FRIES_GAME_OVER_P.png", NULL);
	if (!ptr->sprite || !ptr->ttr) {
		free_sprite(ptr->sprite);
		free_texture(ptr->ttr);
		my_free(ptr);
		return (NULL);
	}
	sfSprite_setTexture(ptr->sprite, ptr->ttr, sfTrue);
	return (ptr);
}

parallax_t *init_go_parallax(void)
{
	parallax_t *ptr = malloc(sizeof(parallax_t));

	if (ptr == NULL)
		return (NULL);
	ptr->obj = init_parallax_object();
	if (!ptr->obj) {
		my_free(ptr);
		return (NULL);
	}
	ptr->pos.x = 0;
	ptr->pos.y = -1800;
	return (ptr);
}

obj_t *create_button(void)
{
	obj_t *ptr = malloc(sizeof(obj_t));

	if (!ptr)
		return (NULL);
	ptr->sprite = sfSprite_create();
	ptr->ttr = sfTexture_createFromFile("./ressource/\
end_quit_button.png", NULL);
	if (!ptr->sprite || !ptr->ttr) {
		free_sprite(ptr->sprite);
		free_texture(ptr->ttr);
		my_free(ptr);
		return (NULL);
	}
	sfSprite_setTexture(ptr->sprite, ptr->ttr, sfTrue);
	sfSprite_setPosition(ptr->sprite, (sfVector2f){700, 700});
	return (ptr);
}
