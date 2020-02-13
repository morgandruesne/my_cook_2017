/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** graphic header with animations prototype and objects
*/

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "game.h"
#include "graphics.h"
#include "engine.h"
#include "pars.h"

#define	NB_SPRITE	9

/*
	name : nom unique au sprite
	obj : objet sprite
	img : texture du sprite
	pos : position du sprite
	belong_scene : int qui renvoie à quel scène l'objet appartient.
*/

typedef struct obj_s {
	char *name;
	sfSprite	*obj;
	sfTexture	*img;
	sfVector2f	pos;
	int	belong_scene;
} obj_t;

#endif
