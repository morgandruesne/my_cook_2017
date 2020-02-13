/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** loop scene functions : loop on the right functions depending on the scene
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

void reset_actual_tray(engine_t *engine, int i)
{
	int 	y = 0;
	char	*reset = "P=0000000/X=`/Y=`";

	for (y = 0; reset[y] != '\0'; y += 1)
		engine->client[i].tray.tray_value[y] = reset[y];
	engine->client[i].tray.tray_value[y] = '\0';
}

void my_strcopy(engine_t *engine, char *str, int i)
{
	int y = 0;

	for (y = 0; str[y] != '\0'; y += 1) {
		engine->client[i].tray.tray_value[y] = str[y];
		engine->client[i].tray.wish[y] = str[y];
	}
	engine->client[i].tray.wish[y] = '\0';
	engine->client[i].tray.tray_value[y] = '\0';
}

void random_client(engine_t *engine, int i)
{
	int ran = 0;
	static int save = 0;

	while (save == ran) {
		ran = rand()%10;
	}
	save = ran;
	if (engine->client[i].exist == 0) {
		if (ran < 8) {
			engine->client[i].exist = 0;
			engine->client[i].walking = 0;
		}
		if (ran > 8) {
			engine->client[i].exist = 1;
			engine->client[i].walking = 1;
			my_strcopy(engine, "P=0000000/X=`/Y=`", i);
			get_wish_client(engine, i);
		}
	}
}

void get_client(game_t *game, engine_t *engine)
{
	sfTime time = sfClock_getElapsedTime(game->clock[3]);
	float seconds;

	seconds = time.microseconds / 1000000.0;
	if (seconds > 1) {
		for (int i = 0; i <= 4; i++) {
			random_client(engine, i);
		}
		sfClock_restart(game->clock[3]);
	}
}
