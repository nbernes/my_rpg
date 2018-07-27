/*
** EPITECH PROJECT, 2018
** maps.h
** File description:
** maps header file
*/

#ifndef __MAPS_H__
#define __MAPS_H__

#include <stdbool.h>

#define CHECK_ERROR(x) if (x == NULL) return (84);

/* GLOBAL */

extern const int MAP_X;
extern const int MAP_Y;
extern const int SCALING_X;
extern const int SCALING_Y;

/* STRUCT */

typedef enum e_type_stage
{
	PANTRY,
	GARDEN,
	FRONTYARD,
	END,
} type_stage_t;

typedef struct bool_bis {
	bool pantry;
	bool frontyard;
} boolbis_t;

typedef struct s_tile
{
	sfVector2f c1;
	sfVector2f c2;
	sfVector2f c3;
	sfVector2f c4;
} tile_t;

#endif
