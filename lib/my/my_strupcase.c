/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** write every char as uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 97) && (str[i] <= 122))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}