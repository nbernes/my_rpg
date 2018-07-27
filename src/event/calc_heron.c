/*
** EPITECH PROJECT, 2018
** calc_heron.c
** File description:
** ...
*/

#include "proto.h"
#include <math.h>

float calc_heron(float l_a, float l_b, float l_c)
{
	float res = (l_a + l_b + l_c) / 2;

	res = sqrt(res * (res - l_a) * (res - l_b) * (res - l_c));
	return (res);
}
