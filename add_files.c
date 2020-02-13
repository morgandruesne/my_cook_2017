/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** cat
*/

#include "cook.h"

char	*put_zero(char *str, int size)
{
	int i = -1;

	if (str == NULL)
		if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
	while (++i < size)
		str[i] = 0;
	return (str);
}

char	*concat(char *dest, char *src)
{
	int size_src = my_strlen(src);
	int size_dest = my_strlen(dest);
	int i = 0;
	char *final = malloc(sizeof(char) * (size_src + size_dest + 1));

	if (final == NULL)
		return (NULL);
	if (size_src < 0 || size_dest < 0) {
		free(final);
		return (NULL);
	}
	for (int j = 0; dest[j] != '\0'; i++ , j++)
		final[i] = dest[j];
	for (int j = 0; src[j] != '\0'; j++ , i++)
		final[i] = src[j];
	final[i] = '\0';
	return (final);
}

char	*fs_read(int fd, char *buffer, int size)
{
	int i = 0;
	int c = 1;
	char *buff = NULL;

	while (c) {
		buff = put_zero(buff, size);
		i = read(fd, buff, size);
		if (i < size)
			c = 0;
		buffer = concat(buffer, buff);
	}
	return (buffer);
}

char	*get_files(char const *filepath)
{
	int	fd;
	int	size = 5000;
	char	*buffer = NULL;

	if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = fs_read(fd, buffer, size);
	close(fd);
	return (buffer);
}
