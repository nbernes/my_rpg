/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** play introduction at the beginning of the game
*/

#include "proto.h"

int verify_creation_of_text(sfFont** font, sfText** text)
{
	if (*font == NULL || *text == NULL) {
		if (*font != NULL)
			sfFont_destroy(*font);
		if (*text != NULL)
			sfText_destroy(*text);
		return (ERROR);
	}
	return (OK);
}

game_object_t **prepare_sprites(void)
{
	int nb_sprites = 3;
	game_object_t **all_sprites = malloc(sizeof(game_object_t *) * \
(nb_sprites + 1));

	if (all_sprites == NULL)
		return (NULL);
	all_sprites[0] = prepare_potato();
	all_sprites[1] = prepare_carrot();
	all_sprites[2] = prepare_ant();
	all_sprites[3] = NULL;
	for (int i = 0; i < nb_sprites; i++)
		if (all_sprites[i] == NULL)
			return (NULL);
	return (all_sprites);
}

void change_rect_sprite(game_object_t **all_sprites)
{
	if (all_sprites[0]->rect.left < 64) {
		all_sprites[0]->rect.left += 32;
		all_sprites[1]->rect.left += 40;
	} else {
		all_sprites[0]->rect.left = 0;
		all_sprites[1]->rect.left = 0;
	}
	if (all_sprites[2]->rect.left < 128)
		all_sprites[2]->rect.left += 64;
	else
		all_sprites[2]->rect.left = 0;
	for (int i = 0; all_sprites[i] != NULL; i++)
		sfSprite_setTextureRect(all_sprites[i]->sprite, \
all_sprites[i]->rect);
}

void manage_time(sfClock *clock, game_object_t **all_sprites)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 300000.0;

	if (seconds > 0.25) {
		change_rect_sprite(all_sprites);
		sfClock_restart(clock);
	}
}

int play_int(sfRenderWindow* window, sfEvent *event)
{
	game_object_t **all_sprites = prepare_sprites();
	int result = 0;
	sfClock *clock = sfClock_create();
	bool end = false;

	if (all_sprites == NULL)
		return (ERROR);
	while (end != true && sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		manage_introduction(window, event, &end);
		manage_time(clock, all_sprites);
		result = display_introduction(window, all_sprites);
		if (result == ERROR)
			return (ERROR);
		else if (result == 1)
			end = true;
		sfRenderWindow_display(window);
	}
	for (int i = 0; all_sprites[i] != NULL; i++)
		destroy_object(all_sprites[i]);
	return (OK);
}
