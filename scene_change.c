/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** scene changing functions, when click.
*/

#include "cook.h"

void	highscore_change(game_t *game, obj_t **sprite)
{
	if (game->state.anim[2] == 1)
		return;
	game->state.change_scene = (sprite_is_clicked(sprite[26]->obj,
	game->pos_mouse, 1)) ? 1 : game->state.change_scene;
}

void	pause_change(game_t *game, obj_t **sprite)
{
	if (game->state.anim[2] == 1)
		return;
	game->state.change_scene = (sprite_is_clicked(sprite[19]->obj,
	game->pos_mouse, 1)) ? 2 : game->state.change_scene;
	game->state.change_scene = (sprite_is_clicked(sprite[20]->obj,
	game->pos_mouse, 1)) ? 1 : game->state.change_scene;
}

void	menu_change(game_t *game, obj_t **sprite, engine_t *engine)
{
	if (game->state.anim[2] == 1)
		return;
	if (sprite_is_clicked(sprite[5]->obj, game->pos_mouse, 1))
		sfRenderWindow_close(game->window);
	if (sprite_is_clicked(sprite[1]->obj, game->pos_mouse, 1)) {
		reset_engine(game, engine, sprite);
		game->state.change_scene = 2;
	}
	game->state.change_scene = (sprite_is_clicked(sprite[1]->obj,
	game->pos_mouse, 1)) ? 2 : game->state.change_scene;
	game->state.change_scene = (sprite_is_clicked(sprite[3]->obj,
	game->pos_mouse, 1)) ? 5 : game->state.change_scene;
}

void	hall_change(game_t *game, obj_t **sprite, engine_t *engine)
{
	if (game->state.anim[2] == 1)
		return;
	if (engine->time <= 0) {
		game->higtscore = put_in_higtscore(game->higtscore,
		engine->money);
		write_hightscore(game->higtscore);
		game->state.anim[2] = 0;
		game->state.change_scene = 5;
	}
	game->state.change_scene = (sprite_is_clicked(sprite[18]->obj,
	game->pos_mouse, 1)) ? 3 : game->state.change_scene;
	if (sprite_is_clicked(sprite[22]->obj, game->pos_mouse, 3)
	&& engine->select != -1) {
		game->state.change_scene = 4;
	}
}
