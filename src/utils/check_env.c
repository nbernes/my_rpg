/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** check at start of the rpg
*/

#include <stdlib.h>
#include "proto.h"
#include "my.h"

char *fill_compare(char **env, int i)
{
	int y = 0;
	char *compare = NULL;

	while (env[i][y] != '=' && env[i][y] != '\0')
		y++;
	compare = malloc(sizeof(char) * (y + 1));
	if (compare == NULL)
		return (NULL);
	y = 0;
	while (env[i][y] != '=' && env[i][y] != '\0') {
		compare[y] = env[i][y];
		y++;
	}
	compare[y] = '\0';
	return (compare);
}

int check_env(char **env)
{
	int i = 0;
	char *compare = NULL;

	while (env[i] != NULL) {
		compare = fill_compare(env, i);
		if (compare == NULL)
			return (ERROR);
		if (my_strcmp(compare, "DISPLAY") == 0) {
			free(compare);
			return (OK);
		}
		free(compare);
		i++;
	}
	my_putstr("You don't have DISPLAY in your environment.\n");
	return (ERROR);
}
