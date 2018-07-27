/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare scene lose
*/

#include <stdlib.h>
#include "proto.h"

int manage_objects_lose(scene_t *lose_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	lose_scene->objs[0] = create_object("ressource/Game_over.png", \
pos, rect, 1);
	if (lose_scene->objs[0] == NULL)
		return (ERROR);
	return (OK);
}

int manage_buttons_lose(scene_t *lose_scene)
{
	int x = 260;
	sfVector2f size = {200, 80};
	sfVector2f position = {x, (WIN_HEIGHT / 2) - 5};

	for (int i = 0; i < lose_scene->nb_buttons; i++) {
		lose_scene->buttons[i] = malloc(sizeof(button_t));
		if (lose_scene->buttons[i] == NULL)
			return (ERROR);
		lose_scene->buttons[i]->size = size;
		lose_scene->buttons[i]->position = position;
		x += 900;
		position.x = x;
		if (buttoninitialise(lose_scene->buttons[i]) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int manage_text_lose(scene_t *lose_scene)
{
	int x = 350;
	sfVector2f position = {x, (WIN_HEIGHT / 2)};

	for (int i = 0; i < lose_scene->nb_text; i++) {
		lose_scene->text[i] = malloc(sizeof(text_t));
		lose_scene->text[i]->font = sfFont_createFromFile("ressource/\
caviar.ttf");
		if (check_create_text(i, lose_scene))
			return (ERROR);
		sfText_setFont(lose_scene->text[i]->text,	\
lose_scene->text[i]->font);
		sfText_setCharacterSize(lose_scene->text[i]->text, 50);
		sfText_setPosition(lose_scene->text[i]->text, position);
		sfText_setColor(lose_scene->text[i]->text, sfWhite);
		x += 900;
		position.x = x;
		lose_scene->text[i]->disp = 1;
	}
	set_string_lose(lose_scene);
	set_origin_lose(lose_scene);
	return (OK);
}

int prepare_lose(scene_t *lose_scene)
{
	if (lose_scene == NULL)
		return (ERROR);
	lose_scene->nb_objects = 1;
	lose_scene->objs = malloc(sizeof(game_object_t *) * \
lose_scene->nb_objects);
	lose_scene->nb_buttons = 2;
	lose_scene->buttons = malloc(sizeof(button_t *) * \
lose_scene->nb_buttons);
	lose_scene->nb_text = 2;
	lose_scene->text = malloc(sizeof(text_t *) * \
lose_scene->nb_text);
	lose_scene->type = LOSE;
	if (check_malloc_scene(lose_scene) == ERROR)
		return (ERROR);
	if (manage_objects_lose(lose_scene) == ERROR || \
manage_buttons_lose(lose_scene) == ERROR || \
manage_text_lose(lose_scene) == ERROR)
		return (ERROR);
	return (OK);
}
