/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** start game explain at the beginning of the game
*/

#include "proto.h"

void manage_game_explain(sfRenderWindow* window, sfEvent *event, int *value)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event->type == sfEvtMouseButtonReleased || \
event->type == sfEvtKeyReleased)
			*value += 1;
	}
}

void destroy_sprites_explain(game_object_t **sprites, sfClock *clock)
{
	destroy_object(sprites[0]);
	destroy_object(sprites[1]);
	destroy_object(sprites[2]);
	sfClock_destroy(clock);
}

void analyse_time_explain(sfRenderWindow* window, int *value, \
game_object_t **sprites, sfClock *clock)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 300000.0;

	if (*value == 0)
		sfRenderWindow_drawSprite(window, sprites[0]->sprite, NULL);
	else if (*value == 1)
		sfRenderWindow_drawSprite(window, sprites[1]->sprite, NULL);
	else
		sfRenderWindow_drawSprite(window, sprites[2]->sprite, NULL);
	if (seconds > 30) {
		*value += 1;
		sfClock_restart(clock);
	}
}

int start_game_explain(sfRenderWindow* window, sfEvent *event)
{
	game_object_t *sprites[3];
	int value = 0;
	sfClock *clock = sfClock_create();

	sprites[0] = create_object("ressource/1-intro.png",	\
(sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, 1);
	sprites[1] = create_object("ressource/2-intro.png", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, 1);
	sprites[2] = create_object("ressource/3-intro.png", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, 1);
	for (int i = 0; i < 3; i++)
		if (sprites[i] == NULL)
			return (ERROR);
	while (value != 3) {
		sfRenderWindow_clear(window, sfBlack);
		analyse_time_explain(window, &value, sprites, clock);
		manage_game_explain(window, event, &value);
		sfRenderWindow_display(window);
	}
	destroy_sprites_explain(sprites, clock);
	return (0);
}
