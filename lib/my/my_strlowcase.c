/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** write every char as lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 65) && (str[i] <= 90))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}