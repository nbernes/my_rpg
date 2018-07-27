/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set opt of fight menus
*/

#include "fight.h"

void set_opt_positions(opts_t *ptr)
{
	sfText_setPosition(ptr->t1, (sfVector2f){120, 670});
	sfText_setPosition(ptr->t2, (sfVector2f){870, 670});
	sfText_setPosition(ptr->t3, (sfVector2f){120, 770});
	sfText_setPosition(ptr->t4, (sfVector2f){870, 770});
	sfText_setColor(ptr->t1, sfBlack);
	sfText_setColor(ptr->t2, sfBlack);
	sfText_setColor(ptr->t3, sfBlack);
	sfText_setColor(ptr->t4, sfBlack);
	if (ptr->tq != NULL) {
		sfText_setPosition(ptr->tq, (sfVector2f){1320, 855});
		sfText_setColor(ptr->tq, sfBlack);
	}
}

void set_basic_options(opts_t *options)
{
	options->font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(options->t1, options->font);
	sfText_setFont(options->t2, options->font);
	sfText_setFont(options->t3, options->font);
	sfText_setFont(options->t4, options->font);
	sfText_setString(options->t1, "ATTACK");
	sfText_setString(options->t2, "MAGIC");
	sfText_setString(options->t3, "SPELLS");
	sfText_setString(options->t4, "RUN");
}

void set_atk_options(opts_t *options)
{
	options->font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(options->t1, options->font);
	sfText_setFont(options->t2, options->font);
	sfText_setFont(options->t3, options->font);
	sfText_setFont(options->t4, options->font);
	sfText_setFont(options->tq, options->font);
	sfText_setString(options->t1, "FRENCH FRIES");
	sfText_setString(options->t2, "POTATO SLICE");
	sfText_setString(options->t3, "POTATO'PPERCUT");
	sfText_setString(options->t4, "POTATTACK");
	sfText_setString(options->tq, "BACK");
}

void set_magic_options(opts_t *options)
{
	options->font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(options->t1, options->font);
	sfText_setFont(options->t2, options->font);
	sfText_setFont(options->t3, options->font);
	sfText_setFont(options->t4, options->font);
	sfText_setFont(options->tq, options->font);
	sfText_setString(options->t1, "MASHED POTATOES");
	sfText_setString(options->t2, "POTATOXICITY");
	sfText_setString(options->t3, "POTATO BLINK");
	sfText_setString(options->t4, "POTATHOR");
	sfText_setString(options->tq, "BACK");
}

void set_spells_options(opts_t *options)
{
	options->font = sfFont_createFromFile("./ressource/caviar.ttf");
	sfText_setFont(options->t1, options->font);
	sfText_setFont(options->t2, options->font);
	sfText_setFont(options->t3, options->font);
	sfText_setFont(options->t4, options->font);
	sfText_setFont(options->tq, options->font);
	sfText_setString(options->t1, "TUBERHEAL");
	sfText_setString(options->t2, "POTATROVOC'");
	sfText_setString(options->t3, "POTACOAT");
	sfText_setString(options->t4, "POTATRUST");
	sfText_setString(options->tq, "BACK");
}
