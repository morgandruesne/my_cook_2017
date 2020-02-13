/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** draw functions to draw all elements, mainly ui in hall scene
*/

#include "cook.h"

void	panel_draw(game_t *game, obj_t **sprite)
{
	sfVector2f pos = (sfVector2f) {290, 90};
	char name[4][13] = {"fries", "soda1", "soda2", "burger-view"};

	if (game->state.anim[1] == 0) {
		for (int i = 0; i < 4; i++) {
			set_scale(sprite, name[i], (sfVector2f) {3, 3});
			set_pos(sprite, name[i], pos);
			pos.x += 150;
		}
	}
	draw_sprite(game, "panel", sprite);
	for (int j = 0; j < 4; j++)
		draw_sprite(game, name[j], sprite);
}

void 	scale_pos_draw(obj_t **obj, game_t *game, sfVector2f pos, char *name)
{
	set_scale(obj, name, (sfVector2f) {1.8, 1.8});
	set_pos(obj, name, pos);
	draw_sprite(game, name, obj);
}

void	tray_draw(game_t *game, engine_t *engine, obj_t **sprite, int i)
{
	int pos[5] = {90, 440, 790, 1140, 1490};
	char name[3][10] = {"fries", "soda1", "soda2"};
	sfVector2f draw_pos = (sfVector2f) {0, 780};
	int value1 = get_supp(engine->client[i].tray.tray_value, 'X');
	int value2 = get_supp(engine->client[i].tray.tray_value, 'Y');

	draw_pos.x = pos[i];
	if (value1 != -1)
		scale_pos_draw(sprite, game, draw_pos, name[value1]);
	draw_pos.y += 50;
	if (value2 != -1)
		scale_pos_draw(sprite, game, draw_pos, name[value2]);
	draw_burger_m(game, sprite, engine->client[i].tray.tray_value,
	(int[2]){draw_pos.x + 90, draw_pos.y});
}

void	wish_draw(game_t *game, engine_t *engine, obj_t **sprite)
{
	int pos[5] = {50, 400, 750, 1100, 1450};
	char name[3][10] = {"fries", "soda1", "soda2"};
	sfVector2f draw_pos = (sfVector2f) {0, 290};
	int value1 = get_supp(engine->client[engine->select].tray.wish, 'X');
	int value2 = get_supp(engine->client[engine->select].tray.wish, 'Y');

	if (engine->select == -1)
		return;
	draw_pos.x = pos[engine->select];
	if (value1 != -1)
		scale_pos_draw(sprite, game, draw_pos, name[value1]);
	draw_pos.y += 90;
	if (value2 != -1)
		scale_pos_draw(sprite, game, draw_pos, name[value2]);
	draw_burger_m(game, sprite, engine->client[engine->select].tray.wish,
	(int[2]){draw_pos.x + 90, draw_pos.y - 30});
}
