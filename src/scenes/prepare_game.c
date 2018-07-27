/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare scene game
*/

#include <stdlib.h>
#include <string.h>
#include "proto.h"

void manage_objects_game(scene_t *scenes)
{
	sfVector2f vect =  {WIN_WIDTH / 2, WIN_HEIGHT / 2};

	scenes->objs[0] = create_object("ressource/character01.png", vect, \
(sfIntRect) {0, 0, 32, 32}, 1);
	scenes->objs[1] = create_object("ressource/inventory.png", \
(sfVector2f){1100, 10}, (sfIntRect){0, 0, 450, 559}, 0);
	scenes->objs[2] = create_object("ressource/cloud.png", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 1600, 900}, 1);
	scenes->objs[3] = create_object("ressource/message.png", \
(sfVector2f){10, 10}, (sfIntRect){0, 0, 400, 211}, 1);
	scenes->objs[4] = create_object("ressource/scroll.png", \
(sfVector2f){813, 415}, (sfIntRect){0, 0, 33, 33}, 0);
	scenes->objs[5] = create_object("ressource/player_stat.png", \
(sfVector2f){-5, 217}, (sfIntRect){0, 0, 450, 180}, 1);
	scenes->objs[10] = create_object("ressource/Victory.png", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 1600, 900}, 0);
	scenes->objs[11] = create_object("ressource/Victory_part_two.png", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 1600, 900}, 0);
	create_quest_objects(scenes);
	sfTexture_setRepeated(scenes->objs[2]->texture, sfTrue);
}

int fill_other_data(scene_t *scenes)
{
	scenes->actor->level = 0;
	scenes->actor->xp = 0;
	scenes->actor->atk = 10;
	scenes->actor->def = 0;
	scenes->actor->hp = 10;
	scenes->actor->skill_point = 0;
	scenes->actor->inventory = NULL;
	scenes->actor->inventory = malloc(sizeof(game_object_t *) * 25);
	if (scenes->actor->inventory == NULL)
		return (ERROR);
	scenes->actor->inventory[0] = malloc(sizeof(game_object_t));
	if (scenes->actor->inventory[0] == NULL)
		return (ERROR);
	return (0);
}

int fill_actor(scene_t *scenes)
{
	manage_objects_game(scenes);
	for (int i = 0; i < scenes->nb_objects; i++)
		if (scenes->objs[i] == NULL)
			return (ERROR);
	scenes->nb_quest = 1;
	scenes->quest = malloc(sizeof(quest_t));
	if (alloc_quest(scenes) == ERROR)
		return (ERROR);
	scenes->actor = malloc(sizeof(actor_t));
	if (scenes->actor == NULL)
		return (ERROR);
	if (fill_other_data(scenes) == ERROR)
		return (ERROR);
	for (int i = 0; i < 1; i++)
		memset(scenes->actor->inventory[i], 0, sizeof(game_object_t));
	scenes->actor->inventory[1] = NULL;
	return (0);
}

int init_element_nbr(scene_t *scenes)
{
	scenes->nb_objects = 12;
	scenes->objs = malloc(sizeof(game_object_t *) * \
scenes->nb_objects);
	scenes->nb_buttons = 0;
	scenes->buttons = NULL;
	scenes->nb_text = 12;
	scenes->text = malloc(sizeof(text_t *) * scenes->nb_text);
	return (0);
}

int prepare_game(scene_t *scenes)
{
	if (scenes == NULL)
		return (ERROR);
	scenes->type = GAME;
	if (init_element_nbr(scenes) == ERROR)
		return (ERROR);
	if (create_quest_text(scenes) == ERROR)
		return (ERROR);
	create_hero_text(scenes);
	if (scenes->objs == NULL)
		return (ERROR);
	if (fill_actor(scenes) == ERROR)
		return (ERROR);
	scenes->map = create_map();
	if (!scenes->map)
		return (ERROR);
	scenes->stage = PANTRY;
	scenes->pnj = sfClock_create();
	scenes->enemies.pantry = true;
	scenes->enemies.frontyard = true;
	return (OK);
}
