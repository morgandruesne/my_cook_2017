/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** basic functions
*/

#include "cook.h"

int 	my_strcmp(char *str, char *str2)
{
	int a = my_strlen(str);
	int b = my_strlen(str2);

	if (a != b)
		return (0);
	for (int i = 0; (str[i] != '\0' && str2[i] != '\0') && str; i += 1)
		if (str[i] != str2[i])
			return (0);
	return (1);
}

int	my_strlen(char const *str)
{
	int	nb_char = 0;

	if (!str)
		return (0);
	for (nb_char = 0; str[nb_char] != '\0'; nb_char += 1);
	return (nb_char);
}

int 	my_getnbr(char *str)
{
	int nb = 0;
	int i = 0;
	int moins = 1;

	if (str[0] == '-') {
		moins = -1;
		i += 1;
	}
	for (; str[i] >= '0' && str[i] <= '9'; i++)
		nb = nb * 10 + str[i] - '0';
	nb *= moins;
	return (nb);
}