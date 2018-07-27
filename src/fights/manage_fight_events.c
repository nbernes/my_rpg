/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** manage fight events
*/

#include "fight.h"

int select_option(sfMouseButtonEvent mouse)
{
	if (select_opt_one(mouse.x, mouse.y) == true)
		return (1);
	if (select_opt_two(mouse.x, mouse.y) == true)
		return (2);
	if (select_opt_three(mouse.x, mouse.y) == true)
		return (3);
	if (select_opt_four(mouse.x, mouse.y) == true)
		return (4);
	if (select_opt_back(mouse.x, mouse.y) == true)
		return (-1);
	return (0);
}

void selector(sfMouseButtonEvent mouse, id_menu_t *select, int *inst)
{
	int crate;

	crate = select_option(mouse);
	if (*select == BASIC) {
		if (crate > 0) {
			*select = crate;
			inst[0] = crate;
		}
	} else {
		if (crate == -1) {
			*select = BASIC;
			inst[0] = 0;
		} else if (crate != 0) {
			*select = END_MENU;
			inst[1] = crate;
		}
	}
}

void fight_event(sfRenderWindow *window, id_menu_t *select, int *inst)
{
	sfEvent evt;

	if (sfRenderWindow_pollEvent(window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (evt.type == sfEvtMouseButtonReleased) {
			selector(evt.mouseButton, select, inst);
		}
	}
}
