/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fight header
*/

#ifndef __FIGHT_H__
#define __FIGHT_H__

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scene.h"

typedef struct s_ints_crate
{
	int x;
	int y;
	int z;
} ints_crate_t;

typedef struct s_instructions_texts
{
	sfText *t1;
	sfText *t2;
	sfFont *font;
} instructions_t;

typedef struct s_chrono_struct
{
	sfClock *clock;
	sfTime time;
	float my_sec;
} chrono_t;

typedef enum e_id_menu
{
	BASIC,
	ATTACK,
	MAGIC,
	SPELLS,
	NB_MENUS,
	END_MENU,
} id_menu_t;

typedef struct s_options_menu
{
	sfText *t1;
	sfText *t2;
	sfText *t3;
	sfText *t4;
	sfText *tq;
	sfFont *font;
} opts_t;

typedef struct s_fight_menu_structure
{
	sfSprite *sprite;
	sfTexture *texture;
	opts_t *options;
} menu_t;

typedef struct s_background_struct
{
	sfSprite *sprite;
	sfTexture *ttr;
} obj_t;

typedef struct s_particles
{
	bool active;
	double life;
	double fade;
	sfColor color;
	sfVector2f position;
	sfVector2f speed;
	sfTexture* texture;
	sfSprite* sprite;
} particles_t;

typedef struct s_ennemy
{
	obj_t *obj;
	int hp;
	int atk;
	int arm;
	int exp;
} ennemy_t;

typedef struct s_fight_container
{
	int status;
	menu_t *menus;
	id_menu_t select;
	obj_t *background;
	int *inst;
	ennemy_t *ennemy;
	particles_t *particles;
} fight_t;

char *int_to_str(int);
void fight_event(sfRenderWindow *, id_menu_t *, int *);
sfColor get_inst_color(int);

/* creation fcts */

chrono_t *create_chrono(void);
ennemy_t *create_ennemy(int);
fight_t *create_fight_container(int);
particles_t *init_particles(char *, float, float);
menu_t *prepare_menus(void);
void reset_values(fight_t *);
void restart_particles(particles_t *, float, float);

/* turn handling fcts */

void attack_ennemy(actor_t *, fight_t *);
void defend_ennemy(sfRenderWindow *, fight_t *, actor_t *);
void fight_scene(sfRenderWindow *, fight_t *, int);
void run_potato(sfRenderWindow *, int);

/* draw fcts */

void draw_fight(sfRenderWindow *, menu_t *, fight_t *, int);
void draw_fight_scene(sfRenderWindow *, fight_t *, int);
void draw_fighters(sfRenderWindow *, fight_t *, int);
void draw_index(sfRenderWindow *, int);
void draw_particles(sfRenderWindow*, particles_t *);
void print_life(sfRenderWindow *, int);

/* select opts */

bool select_opt_one(int, int);
bool select_opt_two(int, int);
bool select_opt_three(int, int);
bool select_opt_four(int, int);
bool select_opt_back(int, int);

/* set menus fcts */

obj_t *get_basic_menu(void);
char *get_inst(int *);
obj_t *set_background(int);
void set_basic_options(opts_t *);
void set_atk_options(opts_t *);
void set_spells_options(opts_t *);
void set_magic_options(opts_t *);
void set_opt_positions(opts_t *);
instructions_t *set_sentences(int *);

/* free fcts */

void free_obj(obj_t *);
void free_chrono(chrono_t *);
void free_instructions(instructions_t *);
void free_sprite(sfSprite *);
void free_texture(sfTexture *);
void free_text(sfText *);
void free_font(sfFont *);
void my_free(void *);
void free_menus(menu_t *);
void free_fight_container(fight_t *);

#endif
