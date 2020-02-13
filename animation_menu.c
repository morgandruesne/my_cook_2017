/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** nice effect for the menu
*/

#include "cook.h"

sfTexture	**load_hover_buttons(void)
{
	sfTexture	**img = malloc(sizeof(sfTexture*) * 14);

	img[0] = sfTexture_createFromFile("img/play_s.png", NULL);
	img[1] = sfTexture_createFromFile("img/highscore_s.png", NULL);
	img[2] = sfTexture_createFromFile("img/settings_s.png", NULL);
	img[3] = sfTexture_createFromFile("img/quit_s.png", NULL);
	img[4] = sfTexture_createFromFile("img/pause_s.png", NULL);
	img[5] = sfTexture_createFromFile("img/yes_s.png", NULL);
	img[6] = sfTexture_createFromFile("img/no_s.png", NULL);
	img[7] = sfTexture_createFromFile("img/play.png", NULL);
	img[8] = sfTexture_createFromFile("img/highscore.png", NULL);
	img[9] = sfTexture_createFromFile("img/settings.png", NULL);
	img[10] = sfTexture_createFromFile("img/quit.png", NULL);
	img[11] = sfTexture_createFromFile("img/pause.png", NULL);
	img[12] = sfTexture_createFromFile("img/yes.png", NULL);
	img[13] = sfTexture_createFromFile("img/no.png", NULL);
	return (img);
}

void	hover_buttons(game_t *game, obj_t **sprite)
{
	static sfTexture	**img = NULL;
	int 			actual[7] = {1, 3, 4, 5, 18, 19, 20};

	img = (img == NULL) ? load_hover_buttons() : img;
	for (int i = 0; i < 7; i++) {
		if (mouse_is_hover(sprite[actual[i]]->obj, game->pos_mouse)) {
			sfSprite_setTexture(sprite[actual[i]]->obj, img[i],
			sfTrue);
		}
		if (!mouse_is_hover(sprite[actual[i]]->obj, game->pos_mouse)) {
			sfSprite_setTexture(sprite[actual[i]]->obj, img[i + 7],
			sfTrue);
		}
	}
}

void	animation_hall(game_t *game, obj_t **sprite)
{
	sfTime 	current_time = sfClock_getElapsedTime(game->clock[1]);
	static int 	step = 0;

	if (sfTime_asSeconds(current_time) < 0.01 ||
	game->state.anim[1] == 0) {
		step = 0;
		return;
	}
	step += 1;
	sfSprite_move(sprite[7]->obj, (sfVector2f) {0, 10});
	sfSprite_move(sprite[13]->obj, (sfVector2f) {0, 10});
	sfSprite_move(sprite[14]->obj, (sfVector2f) {0, 10});
	sfSprite_move(sprite[15]->obj, (sfVector2f) {0, 10});
	sfSprite_move(sprite[22]->obj, (sfVector2f) {0, 10});
	sfClock_restart(game->clock[1]);
	if (step == 30)
		game->state.anim[1] = 0;
}

void 	parralax_right(obj_t *sprite, sfRenderWindow *window, float speed)
{
	sfVector2f	newpos;

	newpos.x = sprite->pos.x - 1921.92;
	newpos.y = 0;
	sfSprite_setPosition(sprite->obj, newpos);
	sfRenderWindow_drawSprite(window, sprite->obj, NULL);
	sfSprite_setPosition(sprite->obj, sprite->pos);
	sfRenderWindow_drawSprite(window, sprite->obj, NULL);
	sprite->pos.x -= speed;
	if (sprite->pos.x < 0)
		sprite->pos.x = 1921.92;
}

void	animation_menu(game_t *game, obj_t **sprite)
{
	sfTime 	current_time = sfClock_getElapsedTime(game->clock[0]);
	static int 	step = 0;

	hover_buttons(game, sprite);
	if (sfTime_asSeconds(current_time) < 0.01 ||
	game->state.anim[0] == 0) {
		step = 0;
		return;
	}
	step += 1;
	for (int i = 1; i < 6; i++)
		sfSprite_move(sprite[i]->obj, (sfVector2f) {-10, 0});
	sfClock_restart(game->clock[0]);
	if (step == 60)
		game->state.anim[0] = 0;
}