/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** Description
*/

#include "cook.h"

void 	set_scale(obj_t **sprite, char *str, sfVector2f scale)
{
	sfSprite_setScale(sprite[search_obj_by_name(sprite, str)]->obj, scale);
}

void	draw_sprite(game_t *game, char *str, obj_t **sprite)
{
	sfRenderWindow_drawSprite(game->window,
	sprite[search_obj_by_name(sprite, str)]->obj,NULL);
}

void	set_pos(obj_t **sprit, char *str, sfVector2f pos)
{
	sfSprite_setPosition(sprit[search_obj_by_name(sprit, str)]->obj, pos);
}