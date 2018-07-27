/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** test objects
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "proto.h"

Test(my_rpg, all_good)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};
	game_object_t *object = create_object("ressource/pnj_01.png", \
pos, rect, 1);

	cr_assert_neq(object, NULL);
	destroy_object(object);
}

Test(my_rpg, null)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};
	game_object_t *object = create_object("ressource/test.png", \
pos, rect, 1);

	cr_assert_eq(object, NULL);
	destroy_object(object);
}
