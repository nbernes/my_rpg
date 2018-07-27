/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** create window
*/

#include "proto.h"
#include "my.h"

sfRenderWindow* create_window(void)
{
	sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
	sfRenderWindow* window = sfRenderWindow_create(mode, "My RPG", \
sfClose, NULL);

	if (window == NULL) {
		my_putstr("Error in Window creation process\n");
		return (NULL);
	}
	sfRenderWindow_setFramerateLimit(window, 50);
	return (window);
}
