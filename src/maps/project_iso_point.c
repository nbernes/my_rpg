/*
** EPITECH PROJECT, 2018
** project_iso_point
** File description:
** ...
*/

#include <math.h>
#include "proto.h"
#include "maps.h"

sfVector2f project_iso_point(int x, int y)
{
	sfVector2f angle = {45 * M_PI / 180, 24 * M_PI / 180};
	sfVector2f point;

	point.x = WIN_WIDTH / 2 + (cos(angle.x) * x - cos(angle.x) * y);
	point.y = WIN_HEIGHT / 2 + WIN_HEIGHT / 4 - SCALING_Y * MAP_Y / 2 + \
(sin(angle.y) * y + sin(angle.y) * x);
	return (point);
}
