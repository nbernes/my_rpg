/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free parallax
*/

#include "end.h"

void free_parallax(parallax_t *ptr)
{
	if (!ptr)
		return;
	free_obj(ptr->obj);
	my_free(ptr);
}
