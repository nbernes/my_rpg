/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** fight
*/

#include <time.h>
#include <stdio.h>
#include "fight.h"
#include "proto.h"

instructions_t *set_sentences(int *inst)
{
	instructions_t *crate = malloc(sizeof(instructions_t));

	if (crate == NULL)
		return (NULL);
	crate->t1 = sfText_create();
	crate->t2 = sfText_create();
	crate->font = sfFont_createFromFile("./ressource/\
caviar.ttf");
	sfText_setFont(crate->t1, crate->font);
	sfText_setFont(crate->t2, crate->font);
	sfText_setPosition(crate->t1, (sfVector2f){130, 650});
	sfText_setPosition(crate->t2, (sfVector2f){300, 700});
	sfText_setScale(crate->t2, (sfVector2f){4, 4});
	sfText_setColor(crate->t2, get_inst_color(inst[0]));
	sfText_setString(crate->t1, "Potato uses:");
	sfText_setString(crate->t2, get_inst(inst));
	return (crate);
}

void evolve_fight(sfRenderWindow *window, fight_t *fgt, actor_t *actor)
{
	if (fgt->select != END_MENU) {
		if (fgt->select == NB_MENUS) {
			run_potato(window, actor->hp);
			reset_values(fgt);
			return;
		}
		draw_fight(window, &fgt->menus[fgt->select], fgt, actor->hp);
		sfRenderWindow_display(window);
		fight_event(window, &fgt->select, fgt->inst);
	} else {
		fight_scene(window, fgt, actor->hp);
		attack_ennemy(actor, fgt);
		reset_values(fgt);
		if (fgt->ennemy->hp <= 0)
			return;
		defend_ennemy(window, fgt, actor);
	}
}

void copy_stats(actor_t *actor, actor_t *tmp)
{
	tmp->hp = actor->hp;
	tmp->def = actor->hp;
}

void end_fight_victorious(actor_t *actor, fight_t *fgt, ints_crate_t *crate)
{
	actor->xp += fgt->ennemy->exp;
	actor->hp = crate->x;
	actor->atk = crate->y;
	actor->def = crate->z;
}

int fight(sfRenderWindow *window, actor_t *actor, int status)
{
	fight_t *fgt = create_fight_container(status);
	ints_crate_t crate = {actor->hp, actor->atk, actor->def};

	srand(time(NULL));
	if (!fgt)
		return (ERROR);
	while (actor->hp > 0 && fgt->ennemy->hp > 0 \
&& sfRenderWindow_isOpen(window) == sfTrue)
		evolve_fight(window, fgt, actor);
	if (actor->hp <= 0) {
		free_fight_container(fgt);
		return (-1);
	} else if (fgt->ennemy->hp <= 0) {
		actor->xp += fgt->ennemy->exp;
		free_fight_container(fgt);
		end_fight_victorious(actor, fgt, &crate);
		return (1);
	}
	free_fight_container(fgt);
	return (1);
}
