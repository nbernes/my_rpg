/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** test check env
*/

#include <criterion/criterion.h>
#include "proto.h"

Test(my_rpg, with_display)
{
	char *env[2] = {"DISPLAY=:0", NULL};
	int result = check_env(env);

	cr_expect_eq(result, OK);
}

Test(my_rpg, no_display)
{
	char *env[2] = {"PAGER=less", NULL};
	int result = check_env(env);

	cr_expect_eq(result, ERROR);
}
