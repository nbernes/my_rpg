/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare start
*/

#include <stdlib.h>
#include "proto.h"

int manage_objects_start(scene_t *start_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	start_scene->objs[0] = create_object("ressource/Menu_start.png", \
pos, rect, 1);
	if (start_scene->objs[0] == NULL)
		return (ERROR);
	return (OK);
}

int manage_buttons_start(scene_t *start_scene)
{
	int y = (165 + WIN_HEIGHT - (80 * start_scene->nb_buttons +	\
(OFFSET - 80) * (start_scene->nb_buttons - 1))) / 2;
	sfVector2f size = {575, 80};
	sfVector2f position = {505, y};

	for (int i = 0; i < start_scene->nb_buttons; i++) {
		start_scene->buttons[i] = malloc(sizeof(button_t));
		if (start_scene->buttons[i] == NULL)
			return (ERROR);
		start_scene->buttons[i]->size = size;
		start_scene->buttons[i]->position = position;
		y += OFFSET;
		position.y = y;
		if (buttoninitialise(start_scene->buttons[i]) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int manage_text_start(scene_t *start_scene)
{
	int y = ((165 + WIN_HEIGHT - (80 * start_scene->nb_buttons + \
(OFFSET - 80) * (start_scene->nb_buttons - 1))) / 2) + 5;
	sfVector2f position = {(WIN_WIDTH / 2), y};

	for (int i = 0; i < start_scene->nb_text; i++, position.y = y) {
		start_scene->text[i] = malloc(sizeof(text_t));
		start_scene->text[i]->font = sfFont_createFromFile("ressource/\
caviar.ttf");
		if (check_create_text(i, start_scene))
			return (ERROR);
		sfText_setFont(start_scene->text[i]->text,      \
start_scene->text[i]->font);
		sfText_setCharacterSize(start_scene->text[i]->text, 50);
		sfText_setPosition(start_scene->text[i]->text, position);
		sfText_setColor(start_scene->text[i]->text, sfWhite);
		y += OFFSET;
		start_scene->text[i]->disp = 1;
	}
	set_string_start(start_scene);
	set_origin_start(start_scene);
	return (OK);
}

int prepare_start(scene_t *start_scene)
{
	if (start_scene == NULL)
		return (ERROR);
	start_scene->nb_objects = 1;
	start_scene->objs = malloc(sizeof(game_object_t *) *	\
start_scene->nb_objects);
	start_scene->nb_buttons = 5;
	start_scene->buttons = malloc(sizeof(button_t *) *	\
start_scene->nb_buttons);
	start_scene->nb_text = 5;
	start_scene->text = malloc(sizeof(text_t *) *	\
start_scene->nb_text);
	start_scene->type = START;
	if (check_malloc_scene(start_scene) == ERROR)
		return (ERROR);
	if (manage_objects_start(start_scene) == ERROR ||	\
manage_buttons_start(start_scene) == ERROR || \
manage_text_start(start_scene) == ERROR)
		return (ERROR);
	return (OK);
}
