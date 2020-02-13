/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** animation of clients in the game
*/

/*
	CLOCK 4,5,6
*/

#include "cook.h"

void	client_arrival(engine_t *engine, game_t *game, int id, int posx)
{
	sfTime 		current_time = sfClock_getElapsedTime(game->clock[4]);
	sfVector2f	pos_sprite;

	if (sfTime_asSeconds(current_time) < 0.01)
		return;
	pos_sprite = sfSprite_getPosition(engine->client[id].obj);
	pos_sprite.x += 10;
	sfSprite_setPosition(engine->client[id].obj, pos_sprite);
	if (pos_sprite.x == posx) {
		pos_sprite.y += 20;
		sfSprite_setPosition(engine->client[id].obj, pos_sprite);
		engine->client[id].in_place = 1;
		engine->client[id].walking = 0;
	}
}

void	animation_client_arrival(engine_t *engine, game_t *game)
{
	int 	pos[5] = {120, 470, 820, 1170, 1520};

	for (int i = 0; i < 5; i++) {
		if (engine->client[i].walking == 1)
			client_arrival(engine, game, i, pos[i]);
	}
	sfClock_restart(game->clock[4]);
}

void	client_departure(engine_t *engine, game_t *game, int id, int posx)
{
	sfTime 		current_time = sfClock_getElapsedTime(game->clock[6]);
	sfVector2f	pos_sprite;
	sfVector2f	reset_pos = (sfVector2f) {-100, 430};

	if (sfTime_asSeconds(current_time) < 0.01)
		return;
	pos_sprite = sfSprite_getPosition(engine->client[id].obj);
	if (pos_sprite.x > posx - 10 && pos_sprite.x < posx + 10)
		pos_sprite.y -= 10;
	pos_sprite.x += 10;
	sfSprite_setPosition(engine->client[id].obj, pos_sprite);
	if (pos_sprite.x >= 2000) {
		engine->client[id].walking = 0;
		engine->client[id].exist = 0;
		sfSprite_setPosition(engine->client[id].obj, reset_pos);
	}
}

void	animation_client_departure(engine_t *engine, game_t *game)
{
	int 	pos[5] = {120, 470, 820, 1170, 1520};

	for (int i = 0; i < 5; i++) {
		if (engine->client[i].walking == 2)
			client_departure(engine, game, i, pos[i]);
	}
	sfClock_restart(game->clock[6]);
}

void	animation_client_waiting(engine_t *engine, game_t *game)
{
	static int 	frame = 0;
	sfVector2f	pos;
	sfTime 		current_time = sfClock_getElapsedTime(game->clock[5]);

	if (sfTime_asSeconds(current_time) < 1)
		return;
	for (int i = 0; i < 5; i++) {
		if (engine->client[i].in_place == 1) {
			pos = sfSprite_getPosition(engine->client[i].obj);
			pos.x = (frame == 0) ? pos.x + 5 : pos.x - 5;
			pos.y = (frame == 0) ? pos.y + 5 : pos.y - 5;
			sfSprite_setPosition(engine->client[i].obj, pos);
		}
	}
	sfClock_restart(game->clock[5]);
	frame = (frame == 0) ? 1 : 0;
}