/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** engine header with prototypes and struct
*/

#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "game.h"
#include "graphics.h"
#include "engine.h"
#include "pars.h"

#define	INIT_TIME	60

typedef struct command_s {
	char	tray_value[18];
	char	wish[18];
} command_t;

typedef struct client_s {
	sfSprite	*obj;
	int		in_place;
	int 		walking;
	command_t	tray;
	int 		exist;
	sfSprite	*button[2];
} client_t;

typedef struct engine_s {
	int	time;
	int	money;
	int 	select;
	int	total_money;
	struct client_s	client[5];
} engine_t;

#endif
