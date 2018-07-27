/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** free
*/

#include "proto.h"

void free_game_data(particles_t *particles, sfClock *clock)
{
	for (int i = 0; i < MAX_PART_LEAF; i++) {
		if (particles[i].sprite != NULL)
			sfSprite_destroy(particles[i].sprite);
		if (particles[i].texture != NULL)
			sfTexture_destroy(particles[i].texture);
	}
	sfClock_destroy(clock);
}
