/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** main
*/

#include "proto.h"

int main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1 || check_env(env) == ERROR)
		return (ERROR);
	if (prepare_gameplay() == ERROR)
		return (ERROR);
	return (OK);
}
