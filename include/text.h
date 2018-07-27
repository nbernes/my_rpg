/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** text
*/

#include <SFML/Graphics.h>

#ifndef __TEXT_H_
#define __TEXT_H_

typedef struct s_text
{
	sfFont* font;
	sfText* text;
	sfVector2f pos_text;
	int disp;
} text_t;

#endif
