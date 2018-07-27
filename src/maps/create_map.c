/*
** EPITECH PROJECT, 2018
** create_map
** File description:
** create the world map
*/

#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "proto.h"

int write_file_contents(char *line, sfVector3f **map, int y)
{
	char **contents = NULL;
	int x = 0;

	if (line == NULL)
		return (OK);
	contents = my_str_to_word_array(line);
	for (; contents[x] != NULL; x++);
	if (x != MAP_X)
		return (ERROR);
	for (x = 0; contents[x] != NULL && x < MAP_X; x++) {
		if (my_str_isnum(contents[x]) != 0)
			return (ERROR);
		map[y][x].z = my_getnbr(contents[x]);
	}
	if (x < MAP_X)
		return (ERROR);
	unset_double_arr(contents);
	return (OK);
}

int read_file(const char *path, sfVector3f **map)
{
	int fd = open(path, O_RDONLY);
	char *line = NULL;
	int y = 0;

	if (fd == -1)
		return (ERROR);
	do {
		if (line != NULL)
			free(line);
		line = get_next_line(fd);
		if (y >= MAP_Y && line != NULL)
			return (ERROR);
		if (write_file_contents(line, map, y) == ERROR)
			return (ERROR);
		y++;
	} while (line != NULL);
	if (y < MAP_Y)
		return (ERROR);
	return (OK);
}

sfVector3f **change_map(sfVector3f **map, const char *path, \
type_stage_t stage, boolbis_t *enemies)
{
	sfVector2i cnt;
	sfVector2f tmp;

	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X; cnt.x++) {
			tmp = \
project_iso_point(cnt.x * SCALING_X, cnt.y * SCALING_Y);
			map[cnt.y][cnt.x].x = tmp.x;
			map[cnt.y][cnt.x].y = tmp.y;
		}
	}
	if (read_file(path, map) == ERROR)
		return (NULL);
	if (stage == PANTRY && enemies->pantry == false)
		map[3][15].z = 0;
	if (stage == FRONTYARD && enemies->frontyard == false)
		map[1][5].z = 0;
	return (map);
}

sfVector3f **create_map(void)
{
	sfVector3f **map = NULL;
	sfVector2i cnt = {0, 0};
	boolbis_t enemies = {true, true};

	map = (sfVector3f **)malloc(sizeof(sfVector3f *) * (MAP_Y + 1));
	if (map == NULL)
		return (NULL);
	map[MAP_Y] = NULL;
	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		map[cnt.y] = (sfVector3f *)malloc(sizeof(sfVector3f) * \
(MAP_X + 1));
		if (map[cnt.y] == NULL)
			return (NULL);
	}
	map = change_map(map, "ressource/maps/pantry/pantry.txt", \
PANTRY, &enemies);
	return (map);
}
