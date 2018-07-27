/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** prepare scene pause
*/

#include <stdlib.h>
#include "proto.h"

int manage_objects_pause(scene_t *pause_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	pause_scene->objs[0] = create_object("ressource/Menu_pause.png", \
pos, rect, 1);
	if (pause_scene->objs[0] == NULL)
		return (ERROR);
	return (OK);
}

int manage_buttons_pause(scene_t *pause_scene)
{
	int y = (165 + WIN_HEIGHT - (80 * pause_scene->nb_buttons + \
(OFFSET - 80) * (pause_scene->nb_buttons - 1))) / 2;
	sfVector2f size = {575, 80};
	sfVector2f position = {505, y};

	for (int i = 0; i < pause_scene->nb_buttons; i++) {
		pause_scene->buttons[i] = malloc(sizeof(button_t));
		if (pause_scene->buttons[i] == NULL)
			return (ERROR);
		pause_scene->buttons[i]->size = size;
		pause_scene->buttons[i]->position = position;
		y += OFFSET;
		position.y = y;
		if (buttoninitialise(pause_scene->buttons[i]) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int manage_text_pause(scene_t *pause_scene)
{
	int y = ((165 + WIN_HEIGHT - (80 * pause_scene->nb_buttons +	\
(OFFSET - 80) * (pause_scene->nb_buttons - 1))) / 2) + 5;
	sfVector2f position = {(WIN_WIDTH / 2), y};

	for (int i = 0; i < pause_scene->nb_text; i++, position.y = y) {
		pause_scene->text[i] = malloc(sizeof(text_t));
		pause_scene->text[i]->font = sfFont_createFromFile("ressource/\
caviar.ttf");
		if (check_create_text(i, pause_scene))
			return (ERROR);
		sfText_setFont(pause_scene->text[i]->text,	\
pause_scene->text[i]->font);
		sfText_setCharacterSize(pause_scene->text[i]->text, 50);
		sfText_setPosition(pause_scene->text[i]->text, position);
		sfText_setColor(pause_scene->text[i]->text, sfWhite);
		y += OFFSET;
		pause_scene->text[i]->disp = 1;
	}
	set_string_pause(pause_scene);
	set_origin_pause(pause_scene);
	return (OK);
}

int prepare_pause(scene_t *pause_scene)
{
	if (pause_scene == NULL)
		return (ERROR);
	pause_scene->nb_objects = 1;
	pause_scene->objs = malloc(sizeof(game_object_t *) * \
pause_scene->nb_objects);
	pause_scene->nb_buttons = 3;
	pause_scene->buttons = malloc(sizeof(button_t *) * \
pause_scene->nb_buttons);
	pause_scene->nb_text = 3;
	pause_scene->text = malloc(sizeof(text_t *) * \
pause_scene->nb_text);
	pause_scene->type = PAUSE;
	if (check_malloc_scene(pause_scene) == ERROR)
		return (ERROR);
	if (manage_objects_pause(pause_scene) == ERROR || \
manage_buttons_pause(pause_scene) == ERROR || \
manage_text_pause(pause_scene) == ERROR)
		return (ERROR);
	return (OK);
}
