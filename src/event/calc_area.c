/*
** EPITECH PROJECT, 2018
** calc_area.c
** File description:
** ...
*/

#include "proto.h"
#include "maps.h"
#include <math.h>
#include <stdio.h>

float pytha(float x1, float x2, float y1, float y2)
{
	float hyp = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	return (hyp);
}

float calc_kite_ar(float vert_diag, float hor_diag)
{
	float area = 0.5 * (vert_diag) * (hor_diag);

	return (area);
}

float calc_tri_ar(sfVector3f pt1, sfVector3f pt2, sfVector2f pos)
{
	float res = calc_heron(pytha(pt1.x, pt2.x, pt1.y, pt2.y), \
pytha(pt1.x, pos.x, pt1.y, pos.y), pytha(pos.x, pt2.x, pos.y, pt2.y));

	return (res);
}

int identify_which_tile(sfVector3f **map, sfVector2i i, sfVector2f pos, \
int incr)
{
	float kite;
	float chara = 0;

	kite = calc_kite_ar(map[incr][incr].y - map[0][0].y, map[0][incr].x \
- map[incr][0].x);
	chara += calc_tri_ar(map[i.y][i.x], map[i.y][i.x + incr], pos);
	chara += calc_tri_ar(map[i.y][i.x + incr], \
map[i.y + incr][i.x + incr], pos);
	chara += calc_tri_ar(map[i.y + incr][i.x + incr], \
map[i.y + incr][i.x], pos);
	chara += calc_tri_ar(map[i.y + incr][i.x], map[i.y][i.x], pos);
	if (chara < kite + 1)
		return (1);
	return (0);
}

int identify_obst_size(sfVector3f **map, sfVector2i i, sfVector2f pos, \
type_stage_t stage)
{
	int flag = 0;
	int incr = 0;

	if (map[i.y][i.x].z > 0) {
		incr = find_increment((int)map[i.y][i.x].z, stage);
		flag = identify_which_tile(map, i, pos, incr);
	}
	return (flag);
}
