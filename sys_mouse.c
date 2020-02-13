/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** mouse handling : get position, draw on the screen with a sprite cursor
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

int 	mouse_is_hover(sfSprite *elem, sfVector2i pos_click)
{
	sfIntRect 	rect = sfSprite_getTextureRect(elem);

	return (pos_click.x < sfSprite_getPosition(elem).x + rect.width &&
	pos_click.x > sfSprite_getPosition(elem).x &&
	pos_click.y < sfSprite_getPosition(elem).y + rect.height &&
	pos_click.y > sfSprite_getPosition(elem).y);
}

int	sprite_is_clicked(sfSprite *elem, sfVector2i pos_click, double scale)
{
	sfIntRect 	rect = sfSprite_getTextureRect(elem);

	if (!sfMouse_isButtonPressed(sfMouseLeft))
		return (0);
	rect.width *= scale;
	rect.height *= scale;
	return (pos_click.x < sfSprite_getPosition(elem).x + rect.width &&
	pos_click.x > sfSprite_getPosition(elem).x &&
	pos_click.y < sfSprite_getPosition(elem).y + rect.height &&
	pos_click.y > sfSprite_getPosition(elem).y);
}

void	draw_mouse(obj_t **sprite, game_t *game)
{
	sfVector2f	pos;

	game->pos_mouse = sfMouse_getPositionRenderWindow(game->window);
	pos.x = game->pos_mouse.x;
	pos.y = game->pos_mouse.y;
	sfSprite_setPosition(sprite[0]->obj, pos);
	sfRenderWindow_drawSprite(game->window, sprite[0]->obj, NULL);
}

int 	test_hit(sfVector2i top, sfVector2i bot, sfVector2i mause)
{
	if (mause.x < bot.x && mause.x > top.x &&
	mause.y < bot.y && mause.y > top.y) {
		return (1);
	}
	return (0);
}
