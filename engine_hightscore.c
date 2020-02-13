/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** scene event : events depending on the actual scene
*/

#include "cook.h"

int	*get_hightscore(void)
{
	int fb = open("hightscore", O_RDONLY);
	char *line;
	int i = 0;
	int *tab = malloc(sizeof(int) * 9);

	while (i < 9) {
		line = my_get_next_line(fb);
		tab[i] = my_getnbr(line);
		i++;
	}
	return (tab);
}

void	write_hightscore(int *tab)
{
	int fb = open("hightscore", O_WRONLY);
	char *str;
	char c = '\n';

	for (int i = 0; i < 9; i++) {
		str = my_getchar(tab[i]);
		write(fb, str, my_strlen(str));
		write(fb, &c, 1);
	}
	close(fb);
}

int	*put_in_higtscore(int tab[10], int nb)
{
	int *tab2 = malloc(sizeof(int)* 10);
	int i = 0;

	for (; tab[i] > nb && i < 9; i++)
		tab2[i] = tab[i];
	if (i < 9)
		tab2[i++] = nb;
	for(; i < 9; i++)
		tab2[i] = tab[i - 1];
	return (tab2);
}
