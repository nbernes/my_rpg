/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** run potato run!
*/

#include "fight.h"

void draw_run_line(sfRenderWindow *window)
{
	sfText *text;
	sfFont *font;

	text = sfText_create();
	font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(text, font);
	sfText_setString(text, "POTATOES NEVER RUN AWAY AH AAAH!!");
	sfText_setPosition(text, (sfVector2f){60, 700});
	sfText_setScale(text, (sfVector2f){2.5, 2.5});
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}

void run_potato(sfRenderWindow *window, int life)
{
	obj_t *basic_menu = get_basic_menu();
	chrono_t *chrono = create_chrono();

	if (basic_menu == NULL)
		return;
	while (chrono->my_sec < 3) {
		sfRenderWindow_drawSprite(window, basic_menu->sprite, NULL);
		print_life(window, life);
		if (chrono->my_sec >= 1)
			draw_run_line(window);
		chrono->time = sfClock_getElapsedTime(chrono->clock);
		chrono->my_sec = chrono->time.microseconds / 1000000;
		sfRenderWindow_display(window);
	}
	free_chrono(chrono);
	free_obj(basic_menu);
}
