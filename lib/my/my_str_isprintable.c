/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** 1 only printable & 0 other
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((' ' > str[i]) || (str[i] > '~'))
			return (0);
		i++;
	}
	return (1);
}