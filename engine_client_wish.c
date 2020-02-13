/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** cherch client wish random
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

int 	get_supp(char *str, char c)
{
	int i = 0;

	for (; str[i] != c; i++);
	return (str[i + 2] - '`' - 1);
}

char	get_random(void)
{
	char *str = "`abc";
	int i = rand() % 5 + 1;

	if (i >= 1 && i <= 3)
		return (str[i]);
	return ('+');
}

char	*random_menu(void)
{
	char *str = malloc(sizeof(char) * 6);

	str[0] = (rand() % 2) + '0';
	str[1] = '\0';
	return (str);
}

void	get_wish_client(engine_t *engine, int select)
{
	char str[7];
	char *file = concat("menu/", random_menu());
	int fd = open(file, O_RDONLY);

	for (int i = 0; i <= 6; i += 1)
		str[i] = '\0';
	read(fd, &str, 7);
	for (int i = 0; str[i] != '\0'; i += 1)
		fill_tray(engine, str[i], engine->client[select].tray.wish, 0);
	fill_tray(engine, get_random(), engine->client[select].tray.wish, 0);
	fill_tray(engine, get_random(), engine->client[select].tray.wish, 0);
}
