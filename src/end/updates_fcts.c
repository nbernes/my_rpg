/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** update parallaxes
*/

#include "end.h"

void update_parallax_pos(parallax_t *go_para)
{
	go_para->pos.y += 5;
	if (go_para->pos.y >= 0)
		go_para->pos.y = -900;
	sfSprite_setPosition(go_para->obj->sprite, go_para->pos);
}

void draw_game_over(sfRenderWindow *window, parallax_t *game_over)
{
	if (game_over->pos.y < 0) {
		game_over->pos.y += 7;
		sfSprite_setPosition(game_over->obj->sprite, game_over->pos);
	}
	sfRenderWindow_drawSprite(window, game_over->obj->sprite, NULL);
}

void display_end(sfRenderWindow *window, parallax_t *go_pl, \
parallax_t *game_over, int sec)
{
	if (sec >= 1.5) {
		update_parallax_pos(go_pl);
		sfRenderWindow_drawSprite(window, go_pl->obj->sprite, NULL);
	}
	if (sec >= 4)
		draw_game_over(window, game_over);
}
