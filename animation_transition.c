/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** animations for transitions
*/

#include "cook.h"

void	change_scene(game_t *game, int scene)
{
	sfRectangleShape *fade;
	sfTime 		current_time = sfClock_getElapsedTime(game->clock[2]);
	static int 	step = 0;
	static int 	opacity = 0;

	if (sfTime_asSeconds(current_time) < 0.001 ||
	game->state.anim[2] == 0) {
		opacity = 0;
		step = 0;
		return;
	}
	fade = sfRectangleShape_create();
	sfRectangleShape_setSize(fade, (sfVector2f) {1920, 1080});
	opacity = (step < 31) ? opacity + 8 : opacity - 8;
	game->state.scene = (step++ == 31) ? scene : game->state.scene;
	sfRectangleShape_setFillColor(fade, (sfColor){255, 255, 255, opacity});
	sfClock_restart(game->clock[2]);
	sfRenderWindow_drawRectangleShape(game->window, fade, NULL);
	if (step == 62)
		game->state.anim[2] = 0;
}