/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scene .h
*/

#include <SFML/Audio.h>
#include "game_object.h"
#include "text.h"
#include "maps.h"

#ifndef __SCENE_H_
#define __SCENE_H_

typedef enum e_type_scene
{
	START,
	PAUSE,
	CREDITS,
	EXPLAIN,
	PARAMETERS,
	GAME,
	WIN,
	LOSE,
	SCENE_SIZE,
} type_scene_t;

typedef struct s_scene scene_t;

typedef struct s_button
{
	sfRectangleShape *rect;
	sfVector2f position;
	sfVector2f size;
	void (*callback)(sfRenderWindow*, scene_t *, type_scene_t *, \
type_scene_t);
} button_t;

int buttoninitialise(button_t *);
int buttonisclicked(button_t *, sfVector2f);

typedef struct s_quest
{
	int ongoing;
	int done;
	int xp;
	int level_required;
	int items_required;
} quest_t;

typedef struct s_actor
{
	int level;
	int xp;
	int atk;
	int def;
	int hp;
	int skill_point;
	game_object_t **inventory;
} actor_t;

typedef struct s_scene
{
	int nb_objects;
	game_object_t **objs;
	int nb_buttons;
	button_t **buttons;
	int nb_text;
	text_t **text;
	type_scene_t type;
	sfMusic* music;
	sfMusic* fight;
	sfMusic* end;
	int nb_quest;
	quest_t **quest;
	actor_t *actor;
	sfVector3f **map;
	type_stage_t stage;
	sfClock *game;
	sfClock *pnj;
	boolbis_t enemies;
} scene_t;

#endif
