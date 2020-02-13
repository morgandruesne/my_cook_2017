/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** Description
*/

#include "cook.h"
#include "pars.h"
#include "graphics.h"
#include "game.h"

char 	*pars_error(char *str)
{
	int i = 0;

	for (i = 0; str[i] != 'D'; i += 1);
	return (str + i);
}

char 	*get_param(char *str, char *str2)
{
	int y = 0;
	int size_res = 0;
	int i = 0;
	char *res;
	int nb = 0;

	for (i = 0; str2[y] != '\0'; i += 1)
		if (str[i] == str2[y])
			y += 1;
		else
			y = 0;
	for (; str[i] != '\"' && str[i] != '\0'; i += 1)
		size_res += 1;
	res = malloc(sizeof(char) * (size_res));
	i -= size_res;
	for (; str[i] != '\"' && str[i] != '\0'; i += 1, nb += 1)
		res[nb] = str[i];
	res[size_res] = '\0';
	return (res);
}

int 	comp_sprite(char *str)
{
	int nb = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '\n' && str[i + 1] == 't')
			nb += 1;
	return (nb);
}

obj_t	*get_all_param(char *str)
{
	obj_t	*sprite = malloc(sizeof(obj_t));

	sprite->obj = sfSprite_create();
	sprite->name = get_param(str, "class=\"");
	sprite->img = sfTexture_createFromFile(get_param(str, "path=\""), NULL);
	sprite->pos = (sfVector2f) {my_getnbr(get_param(str, "x=\"")),
	my_getnbr(get_param(str, "y=\""))};
	sfSprite_setTextureRect(sprite->obj,
	(sfIntRect){my_getnbr(get_param(str, "gr=\"")),
	my_getnbr(get_param(str, "hr=\"")), my_getnbr(get_param(str, "dr=\"")),
	my_getnbr(get_param(str, "br=\""))});
	sfSprite_setTexture(sprite->obj, sprite->img, sfTrue);
	sfSprite_setPosition(sprite->obj, sprite->pos);
	return (sprite);
}

obj_t	**get_struct_from_xml(void)
{
	char *str;
	int sp = 0;
	int nbsprite = 0;
	obj_t	**sprite;

	str = get_files("entity.morly");
	str = pars_error(str);
	nbsprite = comp_sprite(str);
	sprite = malloc(sizeof(obj_t) * (nbsprite + 1));
	for (int i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == '<')
			i += 11;
		if (str[i - 1] == '\n' && str[i] == 't')
			sprite[sp++] = get_all_param(str + i);
		while (str[i] != '\n' && str[i] != '\0')
			i += 1;
	}
	sprite[sp] = NULL;
	return (sprite);
}
