/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** free player stats
*/

#include <stdlib.h>
#include "proto.h"

void free_stats(char *atk, char *def, char *hp, char *level)
{
	free(atk);
	free(def);
	free(hp);
	free(level);
}

void free_stats_others(char *xp, char *sk_pt)
{
	free(xp);
	free(sk_pt);
}