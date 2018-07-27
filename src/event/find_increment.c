/*
** EPITECH PROJECT, 2018
** find_increment.c
** File description:
** ...
*/

#include "proto.h"

int find_garden_incr(int no)
{
	if (no > 6) {
		if (no < 10)
			return (2);
		else
			return (3);
	}
	return (1);
}

int find_frontyard_incr(int no)
{
	if (no > 4) {
		if (no == 5)
			return (2);
		else if (no == 6)
			return (1);
		else
			return (3);
	}
	return (1);
}

int find_pantry_incr(int no)
{
	if (no == 5 || no == 7)
		return (2);
	return (1);
}

int find_increment(int no, type_stage_t stage)
{
	int incr = 0;

	switch (stage) {
	case FRONTYARD:
		incr = find_frontyard_incr(no);
		break;
	case GARDEN:
		incr = find_garden_incr(no);
		break;
	case PANTRY:
		incr = find_pantry_incr(no);
		break;
	default:
		break;
	}
	return (incr);
}
