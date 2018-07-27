/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free fight menus
*/

#include "fight.h"
#include "proto.h"

void free_obj(obj_t *ptr)
{
	free_sprite(ptr->sprite);
	free_texture(ptr->ttr);
	my_free(ptr);
}

void free_chrono(chrono_t *ptr)
{
	if (!ptr)
		return;
	if (!ptr->clock)
		return;
	else {
		sfClock_destroy(ptr->clock);
		my_free(ptr);
	}
}

void free_menu(menu_t menu)
{
	free_sprite(menu.sprite);
	free_texture(menu.texture);
	free_text(menu.options->t1);
	free_text(menu.options->t2);
	free_text(menu.options->t3);
	free_text(menu.options->t4);
	free_text(menu.options->tq);
}

void free_menus(menu_t *menus)
{
	for (int i = 0; i < NB_MENUS; i++) {
		free_menu(menus[i]);
	}
}

void free_fight_container(fight_t *ptr)
{
	if (!ptr)
		return;
	free_menus(ptr->menus);
	free_obj(ptr->background);
	my_free(ptr->inst);
	free_obj(ptr->ennemy->obj);
	for (int i = 0; i < MAX_PART_BLOOD; i++) {
		free_sprite(ptr->particles[i].sprite);
		free_texture(ptr->particles[i].texture);
	}
	my_free(ptr->particles);
	my_free(ptr);
}
