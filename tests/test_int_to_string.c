/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** test int_to_string
*/

#include <criterion/criterion.h>
#include "proto.h"

Test(my_rpg, simple_nb)
{
	int nb = 3;
	char *result = int_to_string(nb);

	cr_expect_str_eq(result, "3");
}

Test(my_rpg, double_nb)
{
	int nb = 35;
	char *result = int_to_string(nb);

	cr_expect_str_eq(result, "35");
}
