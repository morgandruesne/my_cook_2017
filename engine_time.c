/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** cat
*/

#include "cook.h"

char	*str_fill(char *str, int nbr, int tmp, int length)
{
	int i = 0;

	while (i != length) {
		str[i++] = (nbr / tmp) % 10 + '0';
		tmp /= 10;
	}
	str[i] = '\0';
	return (str);
}

int	nbr_length_getchar(int nbr, int *tmp)
{
	int	length = 0;

	while (nbr / *tmp > 0) {
		*tmp *= 10;
		length++;
	}
	return (length);
}

char	*my_getchar(int nbr)
{
	char	*str;
	int	tmp = 1;
	int	length = 0;

	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	if (nbr == 0)
		return ("0");
	length = nbr_length_getchar(nbr, &tmp);
	tmp /= 10;
	str = str_fill(str, nbr, tmp, length);
	return (str);
}

void	engine_time(game_t *game, engine_t *engine)
{
	sfTime time = sfClock_getElapsedTime(game->clock[7]);
	float seconds;

	seconds = time.microseconds / 1000000.0;
	if (seconds > 1) {
		engine->time -= 1;
		sfClock_restart(game->clock[7]);
	}
}
