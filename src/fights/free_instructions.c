/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free_instructions
*/

#include "fight.h"

void free_instructions(instructions_t *texts)
{
	if (!texts)
		return;
	sfText_destroy(texts->t1);
	sfText_destroy(texts->t2);
	sfFont_destroy(texts->font);
	my_free(texts);
}

void reset_values(fight_t *fgt)
{
	fgt->inst[0] = 0;
	fgt->inst[1] = 0;
	fgt->select = BASIC;
	restart_particles(fgt->particles, 1150, 240);
}
