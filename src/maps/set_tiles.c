/*
** EPITECH PROJECT, 2018
** set_tiles.c
** File description:
** ...
*/

#include <stdio.h>
#include "proto.h"

sfTexture *set_grass_texture(void)
{
	sfTexture *text;
	int number = rand() % 4;

	switch (number) {
	case 1:
		text = \
sfTexture_createFromFile("ressource/maps/garden/grass2.png", NULL); break;
	case 2:
		text = \
sfTexture_createFromFile("ressource/maps/garden/grass3.png", NULL); break;
	case 3:
		text = \
sfTexture_createFromFile("ressource/maps/garden/grass4.png", NULL); break;
	default :
		text = \
sfTexture_createFromFile("ressource/maps/garden/grass1.png", NULL);
	}
	return (text);
}

sfTexture *choose_tile_texture(sfTexture *text, sfVector2i *cnt, \
type_stage_t stage)
{
	switch (stage) {
	case PANTRY:
		text = \
sfTexture_createFromFile("ressource/maps/concrete.png", NULL); break;
	case GARDEN:
		text = set_grass_texture(); break;
	case FRONTYARD:
		if (cnt->y < 2 && cnt->x > 9 && cnt->x < 13)
			text = \
sfTexture_createFromFile("ressource/maps/concrete.png", NULL);
		else
			text = set_grass_texture();
	case END:
		break;
	}
	return (text);
}

sfRenderWindow *set_each_tile(sfRenderWindow *window, tile_t *tile, \
type_stage_t stage, sfVector2i *cnt)
{
	sfConvexShape *shape = sfConvexShape_create();
	sfTexture *text = malloc(sizeof(sfTexture *));

	if (!text)
		return (NULL);
	text = choose_tile_texture(text, cnt, stage);
	if (!shape || !text)
		return (NULL);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setPoint(shape, 0, tile->c1);
	sfConvexShape_setPoint(shape, 1, tile->c2);
	sfConvexShape_setPoint(shape, 2, tile->c3);
	sfConvexShape_setPoint(shape, 3, tile->c4);
	sfConvexShape_setTexture(shape, text, sfTrue);
	sfRenderWindow_drawConvexShape(window, shape, NULL);
	sfConvexShape_destroy(shape);
	sfTexture_destroy(text);
	return (window);
}

sfRenderWindow *set_tiles(sfRenderWindow *window, sfVector3f **map, \
sfVector2i *cnt, type_stage_t stage)
{
	tile_t tile;

	if (cnt->y < MAP_Y - 1 && cnt->x < MAP_X - 1) {
		tile.c1.x = map[cnt->y][cnt->x].x;
		tile.c1.y = map[cnt->y][cnt->x].y;
		tile.c4.x = map[cnt->y][cnt->x + 1].x;
		tile.c4.y = map[cnt->y][cnt->x + 1].y;
		tile.c2.x = map[cnt->y + 1][cnt->x].x;
		tile.c2.y = map[cnt->y + 1][cnt->x].y;
		tile.c3.x = map[cnt->y + 1][cnt->x + 1].x;
		tile.c3.y = map[cnt->y + 1][cnt->x + 1].y;
		window = set_each_tile(window, &tile, stage, cnt);
	}
	return (window);
}
