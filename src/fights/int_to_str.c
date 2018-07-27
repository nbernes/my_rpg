/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** int_to_str
*/

#include "fight.h"

int get_int_size(int nb)
{
	int tmp = nb;
	int size = 0;

	if (nb < 0) {
		size++;
		tmp *= -1;
	}
	for (; tmp > 0; tmp /= 10, size++);
	return (size);
}

char *int_to_str(int nb)
{
	int size = get_int_size(nb);
	char *s = malloc(sizeof(char) * (size + 1));
	int div;
	int i = 0;

	if (nb < 0) {
		s[i++] = '-';
		nb *= -1;
	}
	for (div = 1; nb / div > 9; div *= 10);
	for (; div != 1; s[i++] = nb / div + '0', nb %= div, div /= 10);
	s[i++] = nb + '0';
	s[i] = '\0';
	return (s);
}
