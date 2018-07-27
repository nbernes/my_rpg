/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mouse selection
*/

#include "fight.h"

bool select_opt_one(int x, int y)
{
	if (x >= 100 && x <= 750 && y >= 660 && y <= 730)
		return (true);
	else
		return (false);
}

bool select_opt_two(int x, int y)
{
	if (x >= 850 && x <= 1550 && y >= 660 && y <= 730)
		return (true);
	else
		return (false);
}

bool select_opt_three(int x, int y)
{
	if (x >= 100 && x <= 750 && y >= 760 && y <= 830)
		return (true);
	else
		return (false);
}

bool select_opt_four(int x, int y)
{
	if (x >= 850 && x <= 1550 && y >= 760 && y <= 830)
		return (true);
	else
		return (false);
}

bool select_opt_back(int x, int y)
{
	if (x >= 1300 && x <= 1500 && y >= 840 && y <= 880)
		return (true);
	else
		return (false);
}
