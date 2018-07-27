/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** defend ennemy
*/

#include "fight.h"

void print_ennemy_attack(sfRenderWindow *win)
{
	sfText *atk = sfText_create();
	sfFont *font = sfFont_createFromFile("./ressource/caviar.ttf");

	sfText_setFont(atk, font);
	sfText_setString(atk, "The ennemy is attacking...");
	sfText_setPosition(atk, (sfVector2f){60, 700});
	sfRenderWindow_drawText(win, atk, NULL);
	free_text(atk);
	free_font(font);
}

void get_potato_under_attack(fight_t *fight, actor_t *actor)
{
	if (actor->def == -1)
		actor->hp -= fight->ennemy->atk / (actor->def + 2);
	else
		actor->hp -= fight->ennemy->atk / (actor->def + 1);
}

void defend_ennemy(sfRenderWindow *win, fight_t *fgt, actor_t *actor)
{
	chrono_t *tmp = create_chrono();
	obj_t *basic_menu = get_basic_menu();

	while (tmp->my_sec < 2) {
		sfRenderWindow_drawSprite(win, fgt->background->sprite, NULL);
		sfRenderWindow_drawSprite(win, basic_menu->sprite, NULL);
		draw_fighters(win, fgt, actor->hp);
		if (tmp->my_sec >= 1)
			print_ennemy_attack(win);
		tmp->time = sfClock_getElapsedTime(tmp->clock);
		tmp->my_sec = tmp->time.microseconds / 1000000;
		sfRenderWindow_display(win);
	}
	free_chrono(tmp);
	free_obj(basic_menu);
	get_potato_under_attack(fgt, actor);
}
