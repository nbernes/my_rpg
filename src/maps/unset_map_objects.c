/*
** EPITECH PROJECT, 2018
** unset_objects
** File description:
** ...
*/

#include "proto.h"

void unset_double_arr(char **arr)
{
	for (int cnt = 0; arr[cnt] != NULL; cnt++)
		free(arr[cnt]);
	free(arr);
}

void unset_objects(sfVector3f **map)
{
	for (int cnt = 0; cnt < MAP_Y; cnt++)
		if (map[cnt] != NULL)
			free(map[cnt]);
	if (!map)
		free(map);
}
