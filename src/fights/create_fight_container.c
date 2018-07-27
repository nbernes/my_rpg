/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_fight_container
*/

#include "fight.h"

chrono_t *create_chrono(void)
{
	chrono_t *ptr = malloc(sizeof(*ptr));

	if (!ptr)
		return (NULL);
	ptr->clock = sfClock_create();
	ptr->my_sec = 0;
	return (ptr);
}

bool verify_fight_container(fight_t *ptr)
{
	if (!ptr)
		return (false);
	if (!ptr-> particles || !ptr->menus || \
!ptr->background || !ptr->inst || ptr->status < 0 || ptr->status > 2)
		return (false);
	return (true);
}

fight_t *create_fight_container(int status)
{
	fight_t *ptr = malloc(sizeof(*ptr));

	if (ptr == NULL)
		return (NULL);
	ptr->status = status;
	ptr->particles = init_particles("./ressource/blood.png", 1150, 240);
	ptr->menus = prepare_menus();
	ptr->select = BASIC;
	ptr->ennemy = create_ennemy(status);
	ptr->background = set_background(status);
	ptr->inst = malloc(sizeof(int) * 2);
	if (verify_fight_container(ptr) == false) {
		free_fight_container(ptr);
		return (NULL);
	}
	ptr->inst[0] = 0;
	ptr->inst[1] = 0;
	return (ptr);
}
