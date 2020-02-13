/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** animation of clients in the game
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

int 	my_strncmp(char *str, char *str2, int nb)
{
	int a = my_strlen(str);
	int b = my_strlen(str2);

	if (a != b)
		return (0);
	for (int i = 0; ((str[i] != '\0' && str2[i] != '\0') && str)
	|| i == nb; i += 1)
		if (str[i] != str2[i])
			return (0);
	return (1);
}

void	get_money(engine_t *engine, int i, int more_time)
{
	engine->money += i;
	engine->time += more_time;
}

void	format_tray_command(engine_t *engine)
{
	int extra1;
	int extra2;
	int extra3 = get_supp(engine->client[engine->select].tray.wish, 'X');
	int extra4 = get_supp(engine->client[engine->select].tray.wish, 'Y');

	extra1 = get_supp(engine->client[engine->select].tray.tray_value, 'X');
	extra2 = get_supp(engine->client[engine->select].tray.tray_value, 'Y');
	if (my_strncmp(engine->client[engine->select].tray.tray_value + 2,
	engine->client[engine->select].tray.wish + 2, 7)
	&& engine->select != -1)
		get_money(engine, 10, rand() % 14 + 1);
	if ((extra1 == extra3 || extra1 == extra4) && engine->select != -1)
		get_money(engine, 1, 2);
	if ((extra2 == extra3 || extra2 == extra4) && engine->select != -1)
		get_money(engine, 1, 2);
}
