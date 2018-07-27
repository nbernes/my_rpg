/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Game Over
*/

#include "end.h"
#include "fight.h"

bool is_button_clicked(sfEvent *event)
{
	if (event->type != sfEvtMouseButtonReleased)
		return (false);
	if (event->mouseButton.x >= 700 && event->mouseButton.x <= 900 && \
event->mouseButton.y >= 700 && event->mouseButton.y <= 800)
		return (true);
	return (false);
}

void end_event(sfRenderWindow *window, int sec)
{
	sfEvent evt;

	if (sfRenderWindow_pollEvent(window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (sec >= 8 && is_button_clicked(&evt) == true)
			sfRenderWindow_close(window);
	}
}

void free_end(chrono_t *chrono, parallax_t *go_para, parallax_t *game_over, \
obj_t *button)
{
	free_chrono(chrono);
	free_parallax(go_para);
	free_parallax(game_over);
	free_obj(button);
}

void end(sfRenderWindow *window, scene_t *scene)
{
	chrono_t *chrono = create_chrono();
	parallax_t *go_para = init_go_parallax();
	parallax_t *game_over = set_game_over();
	obj_t *button = create_button();
	sfMusic *music = start_go_music(scene);

	if (!chrono || !go_para || !game_over || !button)
		return (free_end(chrono, go_para, game_over, button));
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		chrono->time = sfClock_getElapsedTime(chrono->clock);
		chrono->my_sec = chrono->time.microseconds / 1000000;
		display_end(window, go_para, game_over, chrono->my_sec);
		if (chrono->my_sec >= 8)
			sfRenderWindow_drawSprite(window, button->sprite, NULL);
		sfRenderWindow_display(window);
		end_event(window, chrono->my_sec);
	}
	free_music(music);
	return (free_end(chrono, go_para, game_over, button));
}
