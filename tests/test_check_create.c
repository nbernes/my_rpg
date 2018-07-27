/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** test check create
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "proto.h"

Test(my_rpg, no_null)
{
	sfVideoMode mode = {1000, 1000, 32};
	sfRenderWindow* window = sfRenderWindow_create(mode, "test", \
sfClose, NULL);
	scene_t *scenes = malloc(sizeof(scene_t));
	int result = check_create(&window, &scenes);

	if (window == NULL || scenes == NULL)
		cr_expect_eq(result, ERROR);
	else
		cr_expect_eq(result, OK);
}

Test(my_rpg, scenes_null)
{
	sfVideoMode mode = {1000, 1000, 32};
	sfRenderWindow* window = sfRenderWindow_create(mode, "test", \
sfClose, NULL);
	scene_t *scenes = NULL;
	int result = check_create(&window, &scenes);

	cr_expect_eq(result, ERROR);
}

Test(my_rpg, window_null)
{
	sfRenderWindow* window = NULL;
	scene_t *scenes = malloc(sizeof(scene_t));
	int result = check_create(&window, &scenes);

	cr_expect_eq(result, ERROR);
}
