/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** Description
*/

#include "cook.h"
#include "pars.h"
#include "game.h"

int	search_obj_by_name(obj_t **sprite, char *str)
{
	int i = 0;

	for (; sprite[i] != NULL; i++) {
		if (my_strcmp(sprite[i]->name, str))
			return (i);
	}
	return (-1);
}
