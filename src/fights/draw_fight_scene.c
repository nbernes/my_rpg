/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** draw fight scene
*/

#include "fight.h"

void draw_fight_scene(sfRenderWindow *window, fight_t *fgt, int life)
{
	obj_t *basic_menu = get_basic_menu();

	if (basic_menu == NULL)
		return;
	sfRenderWindow_drawSprite(window, fgt->background->sprite, NULL);
	sfRenderWindow_drawSprite(window, basic_menu->sprite, NULL);
	draw_index(window, fgt->inst[0]);
	draw_fighters(window, fgt, life);
	free_obj(basic_menu);
}

void fight_scene(sfRenderWindow *window, fight_t *fgt, int life)
{
	chrono_t *tmp = create_chrono();
	instructions_t *texts = set_sentences(fgt->inst);

	sfRenderWindow_drawSprite(window, fgt->background->sprite, NULL);
	while (tmp->my_sec < 3) {
		draw_fight_scene(window, fgt, life);
		if (tmp->my_sec >= 1)
			sfRenderWindow_drawText(window, texts->t1, NULL);
		if (tmp->my_sec >= 2)
			sfRenderWindow_drawText(window, texts->t2, NULL);
		tmp->time = sfClock_getElapsedTime(tmp->clock);
		tmp->my_sec = tmp->time.microseconds / 1000000;
		if (fgt->inst[0] != SPELLS)
			draw_particles(window, fgt->particles);
		sfRenderWindow_display(window);
	}
	free_chrono(tmp);
	free_instructions(texts);
}
