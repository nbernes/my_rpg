/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** displays a specific map
*/

#include "proto.h"
#include "maps.h"

int draw_caption(sfRenderWindow *window)
{
	sfTexture *texture;
	sfSprite *sprite;

	texture = \
sfTexture_createFromFile("ressource/maps/current_map.png", NULL);
	if (!texture)
		return (ERROR);
	sprite = sfSprite_create();
	if (!sprite)
		return (ERROR);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	return (OK);
}

int manage_flag(sfRenderWindow* window, scene_t *scene)
{
	sfImage *pic;

	sfRenderWindow_clear(window, sfTransparent);
	window = draw_map(scene->map, window, scene->stage);
	if (!window)
		return (ERROR);
	pic = sfRenderWindow_capture(window);
	if (window == NULL)
		return (ERROR);
	if (sfImage_saveToFile(pic, "ressource/maps/current_map.png")	\
== sfFalse) {
		sfImage_destroy(pic);
		return (ERROR);
	}
	sfImage_destroy(pic);
	return (0);
}

int create_map_caption(sfRenderWindow *window, scene_t *scene)
{
	static int flag	= 0;
	int err = OK;

	if (flag < 1) {
		flag++;
		if (manage_flag(window, scene) == ERROR)
			return (ERROR);
	} else {
		flag = reset_flag(scene->map, scene->objs[0]->position);
		if (flag == 0) {
			scene->stage =			\
change_stage(scene->objs[0]->position.x, scene->stage);
			err = switch_maps(scene->map,		\
scene->objs[0]->position, scene->stage, &scene->enemies);
			reset_character_pos(&scene->objs[0]->position);
		} if (err == ERROR)
			return (ERROR);
	}
	return (OK);
}
