/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** myrand
*/

#include <stdlib.h>

double myrand(double min, double max)
{
	return (double)(min + ((float)rand() / RAND_MAX * (max - min + 1.0)));
}
