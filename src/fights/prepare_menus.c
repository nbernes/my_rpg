/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** prepare fight menus
*/

#include "fight.h"

obj_t *get_basic_menu(void)
{
	obj_t *ptr = malloc(sizeof(obj_t));
	sfIntRect select_rect = {0, 425, 1600, 425};

	if (ptr == NULL)
		return (NULL);
	ptr->sprite = sfSprite_create();
	ptr->ttr = sfTexture_createFromFile("./ressource/\
battle_menu.png", &select_rect);
	sfSprite_setTexture(ptr->sprite, ptr->ttr, sfTrue);
	sfSprite_setPosition(ptr->sprite, (sfVector2f){0, 475});
	return (ptr);
}

opts_t *set_options(int id)
{
	opts_t *ptr = malloc(sizeof(opts_t));

	if (!ptr)
		return (NULL);
	ptr->t1 = sfText_create();
	ptr->t2 = sfText_create();
	ptr->t3 = sfText_create();
	ptr->t4 = sfText_create();
	if (id == BASIC)
		ptr->tq = NULL;
	else
		ptr->tq = sfText_create();
	switch (id) {
	case BASIC: set_basic_options(ptr); break;
	case ATTACK: set_atk_options(ptr); break;
	case MAGIC: set_magic_options(ptr); break;
	case SPELLS: set_spells_options(ptr); break;
	}
	set_opt_positions(ptr);
	return (ptr);
}

void set_menus(menu_t *menu, int id)
{
	sfIntRect select_rect = {0, 0, 1600, 425};

	menu->sprite = sfSprite_create();
	menu->texture = sfTexture_createFromFile("./ressource/\
battle_menu.png", &select_rect);
	sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
	sfSprite_setPosition(menu->sprite, (sfVector2f){0, 475});
	menu->options = set_options(id);
}

menu_t *prepare_menus(void)
{
	menu_t *menus = malloc(sizeof(menu_t) * NB_MENUS);

	if (menus == NULL)
		return (NULL);
	for (int i = 0; i < NB_MENUS; i++)
		set_menus(&menus[i], i);
	return (menus);
}
