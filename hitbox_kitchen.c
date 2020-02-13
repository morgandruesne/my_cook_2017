/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** hitbox of ingredient in kitchen
*/

#include "cook.h"

int	test_ingredinet_hit_kitchen(sfVector2i mause)
{
	sfVector2i top = {1300, 100};
	sfVector2i bot = {1450, 250};
	int ret = 0;

	for (int i = 1; i <= NB_INGREDIENT; i++) {
		ret = test_hit(top, bot, mause);
		if (ret == 1)
			return (i);
		top.x += 175;
		bot.x += 175;
		if (i % 3 == 0) {
			top.y += 175;
			top.x = 1300;
			bot.y += 175;
			bot.x = 1450;
		}
	}
	return (0);
}

int	test_sauce_hit_kitchen(sfVector2i mause)
{
	if (test_hit((sfVector2i) {150, 590}, (sfVector2i) {220, 830}, mause))
		return (9);
	if (test_hit((sfVector2i) {250, 590}, (sfVector2i) {316, 830}, mause))
		return (10);
	return (0);
}

void	test_quit_hit_kitchen(sfVector2i mause, engine_t *engine, game_t *game)
{
	if (game->state.anim[2] == 1)
		return;
	if (test_hit((sfVector2i) {1410, 660},
	(sfVector2i) {1490, 750}, mause)) {
		game->state.change_scene = 2;
	}
	if (test_hit((sfVector2i) {1560, 660},
	(sfVector2i) {1680, 750}, mause)) {
		game->state.change_scene = 2;
		reset_burger(engine->client[engine->select].tray.tray_value);
	}
}

int	get_all_hit_box(sfVector2i mause, game_t *game, engine_t *engine)
{
	int i = 0;

	i = test_ingredinet_hit_kitchen(mause);
	if (i != 0)
		return (i);
	i = test_sauce_hit_kitchen(mause);
	test_quit_hit_kitchen(mause, engine, game);
	return (i);
}
