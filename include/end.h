/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** end header
*/

#ifndef __END_H__
#define __END_H__

#include "fight.h"

typedef struct s_parallax
{
	obj_t *obj;
	sfVector2f pos;
} parallax_t;

/* free functions */

void free_music(sfMusic *);
void free_parallax(parallax_t *);

/* updates and display functions */

void display_end(sfRenderWindow *, parallax_t *, parallax_t *, int);
void draw_button(obj_t *);
void draw_game_over(sfRenderWindow *, parallax_t *);
void update_parallax_pos(parallax_t *);

/* init and create functions */

obj_t *create_button(void);
parallax_t *init_go_parallax(void);
parallax_t *set_game_over(void);
sfMusic *start_go_music(scene_t *);

#endif
