/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** loop scene functions : loop on the right functions depending on the scene
*/

#include "cook.h"
#include "game.h"
#include "graphics.h"

void	highscore_loop(game_t *game, obj_t **sprite)
{
	if (game->state.scene != 5)
		return;
	sfRenderWindow_clear(game->window, sfBlack);
	menu_events(game);
	highscore_change(game, sprite);
	highscore_draw(game, sprite);
	draw_mouse(sprite, game);
}

void	pause_loop(game_t *game, obj_t **sprite)
{
	if (game->state.scene != 3)
		return;
	sfRenderWindow_clear(game->window, sfBlack);
	menu_events(game);
	pause_change(game, sprite);
	hover_buttons(game, sprite);
	pause_draw(game, sprite);
	draw_mouse(sprite, game);
	if (game->state.anim[2] == 1)
		return;
	for (int i = 0; i < NB_CLOCK; i++)
		sfClock_restart(game->clock[i]);
}

void	hall_loop(game_t *game, obj_t **sprite, engine_t *engine)
{
	if (game->state.scene != 2)
		return;
	get_client(game, engine);
	engine_time(game, engine);
	animation_hall(game, sprite);
	animation_client_arrival(engine, game);
	animation_client_waiting(engine, game);
	animation_client_departure(engine, game);
	hall_draw(game, sprite, engine);
	hall_events(game, engine, sprite);
	hall_change(game, sprite, engine);
}

void	kitchen_loop(game_t *game, obj_t **sprite, engine_t *engine)
{
	if (game->state.scene != 4)
		return;
	set_pos(sprite, "table", (sfVector2f) {0, 290});
	set_scale(sprite, "table", (sfVector2f) {1, 1});
	get_client(game, engine);
	engine_time(game, engine);
	kitchen_events(game, engine);
	hall_change(game, sprite, engine);
	kitchen_draw(game, sprite, engine);
	draw_burger(game, sprite,
	engine->client[engine->select].tray.tray_value, (int[2]) {600, 700});
	draw_wish_burger(game, sprite,
	engine->client[engine->select].tray.wish);
	if (game->state.change_scene != 4) {
		set_pos(sprite, "table", (sfVector2f) {0, 390});
		set_scale(sprite, "table", (sfVector2f){0.75, 0.75});
	}
}

void 	menu_loop(game_t *game, obj_t **sprite, engine_t *engine)
{
	if (game->state.scene != 1)
		return;
	animation_menu(game, sprite);
	menu_change(game, sprite, engine);
	menu_events(game);
	menu_draw(game, sprite);
}
