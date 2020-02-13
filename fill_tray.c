/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** animation of clients in the game
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

char	*put_food(char c, char *tray)
{
	int i = 0;

	for (; tray[i] != '0' && tray[i + 1] != '/'; i++);
	tray[i] = c;
	return (tray);
}

char	*put_extra(char c, char *tray)
{
	int i = 0;

	for (; tray[i] != 'X'; i++);
	if (tray[i + 2] == '`') {
		tray[i + 2] = c;
		return (tray);
	}
	for (; tray[i] != 'Y'; i++);
	tray[i + 2] = c;
	return (tray);
}

char	*fill_tray(engine_t *engine, char c, char *tray, int wish)
{
	char *str = "abc";

	if (c == '+' || c == '0' || c == 0)
		return (tray);
	if (wish == 1 && engine->select == -1)
		return (tray);
	for (int i = 0; str[i] != '\0'; i++)
		if (c == str[i]) {
			return (put_extra(c, tray));
		}
	return (put_food(c, tray));
}
