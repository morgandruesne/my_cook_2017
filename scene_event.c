/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** scene event : events depending on the actual scene
*/

#include "cook.h"

void	hall_interactions(game_t *game, engine_t *engine)
{
	for (int i = 0; i < 5; i++) {
		if (sprite_is_clicked(engine->client[i].obj,
		game->pos_mouse, 6) && engine->client[i].in_place == 1) {
			engine->select = i;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (sprite_is_clicked(engine->client[i].button[1],
		game->pos_mouse, 0.2)) {
			format_tray_command(engine);
			engine->client[i].in_place = 0;
			engine->client[i].walking = 2;
			engine->select = -1;
		}
		if (sprite_is_clicked(engine->client[i].button[0],
		game->pos_mouse, 0.2)) {
			reset_actual_tray(engine, i);
		}
	}
}

void	panel_interactions(game_t *game, engine_t *engine, obj_t **sprite)
{
	if (engine->select == -1)
		return;
	if (sprite_is_clicked(sprite[13]->obj, game->pos_mouse, 3)) {
		fill_tray(engine, 'a',
		engine->client[engine->select].tray.tray_value, 1);
	}
	if (sprite_is_clicked(sprite[14]->obj, game->pos_mouse, 3)) {
		fill_tray(engine, 'b',
		engine->client[engine->select].tray.tray_value, 1);
	}
	if (sprite_is_clicked(sprite[15]->obj, game->pos_mouse, 3)) {
		fill_tray(engine, 'c',
		engine->client[engine->select].tray.tray_value, 1);
	}
}

void	hall_events(game_t *game, engine_t *engine, obj_t **sprite)
{
	while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
		if (game->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(game->window);
		panel_interactions(game, engine, sprite);
		hall_interactions(game, engine);
	}
}

void	kitchen_events(game_t *game, engine_t *engine)
{
	int i = 0;

	while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
		if (game->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(game->window);
		if (game->event.type == sfEvtMouseButtonPressed) {
			i = get_all_hit_box(game->pos_mouse, game, engine);
			fill_tray(engine, i + 48,
			engine->client[engine->select].tray.tray_value, 0);
		}
	}
}

void 	menu_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
		if (game->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(game->window);
	}
}
