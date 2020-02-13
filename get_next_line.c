/*
** EPITECH PROJECT, 2017
** getline
** File description:
** Description
*/

#include "cook.h"

char *my_realloc(char *str, int size, int nb)
{
	char *temp = str;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	for (int i = 0; i <= nb; i++)
		str[i] = temp[i];
	free(temp);
	return (str);
}

char get(int fd)
{
	static char buff[READ_SIZE];
	static int size = 0;
	static int nbr = 0;
	char cha;

	if (nbr == size) {
		size = read(fd, buff, READ_SIZE);
		nbr = 0;
		if (size == 0)
			return ('\0');
	}
	cha = buff[nbr];
	nbr += 1;
	return (cha);
}

char	*my_get_next_line(int fd)
{
	char cha;
	char *final;
	int size = 0;

	final = malloc(READ_SIZE + 1);
	if (final == NULL || fd == -1)
		return (NULL);
	cha = get(fd);
	for (size = 0; cha != '\n' && cha != '\0'; size++) {
		final[size] = cha;
		cha = get(fd);
		if (size % (READ_SIZE + 1) == 0)
			final = my_realloc(final, size + READ_SIZE + 1, size);
	}
	final[size] = '\0';
	return (final);
}
