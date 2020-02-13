/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** reset functions
*/

#include "cook.h"
#include "engine.h"

void reset_engine(game_t *game, engine_t *engine, obj_t **sprite)
{
	engine->time = INIT_TIME;
	engine->select = -1;
	engine->money = 0;
	for (int i = 0; i < 5; i++) {
		sfSprite_setPosition(engine->client[i].obj,
		(sfVector2f) {-100, 430});
		engine->client[i].in_place = 0;
		engine->client[i].walking = 0;
		engine->client[i].exist = 0;
	}
	for (int i = 0; i != NB_CLOCK; i++)
		sfClock_restart(game->clock[i]);
	set_pos(sprite, "table", (sfVector2f) {0, 390});
	set_scale(sprite, "table", (sfVector2f){0.75, 0.75});
}

char	*reset_burger(char *str)
{
	for (int i = 2; str[i] != '/'; i++)
		str[i] = '0';
	return (str);
}
