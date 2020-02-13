/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** scene draw functions : draw obj depending on the actual scene
*/

#include "cook.h"

void	highscore_draw(game_t *game, obj_t **sprite)
{
	static sfFont 	*font = NULL;
	sfText 	*txt;
	int 	height = 350;

	draw_sprite(game, "highscore2", sprite);
	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	for (int i = 0; i < 9; i++) {
		sfText_setPosition(txt, (sfVector2f) {850, height});
		sfText_setString(txt, my_getchar(game->higtscore[i]));
		sfRenderWindow_drawText(game->window, txt, NULL);
		height += 50;
	}
	draw_sprite(game, "back", sprite);
}

void	pause_draw(game_t *game, obj_t **sprite)
{
	static sfFont 	*font = NULL;
	sfText 	*txt;

	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setString(txt, "Resume?");
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setPosition(txt, (sfVector2f) {910, 370});
	sfRenderWindow_drawText(game->window, txt, NULL);
	set_pos(sprite, "pause", (sfVector2f) {840, 300});
	draw_sprite(game, "pause", sprite);
	set_pos(sprite, "yes", (sfVector2f) {690, 500});
	draw_sprite(game, "yes", sprite);
	set_pos(sprite, "no", (sfVector2f) {990, 500});
	draw_sprite(game, "no", sprite);
}

void	kitchen_draw(game_t *game, obj_t **sprite, engine_t *engine)
{
	draw_sprite(game, "kitchen", sprite);
	draw_sprite(game, "table", sprite);
	draw_sprite(game, "ketchup", sprite);
	draw_sprite(game, "carrot", sprite);
	ui_hall_draw(game, sprite, engine);
	ui_ingredients_draw(game, sprite);
	draw_sprite(game, "button_valid", sprite);
	draw_sprite(game, "button_cros", sprite);
	draw_sprite(game, "light", sprite);
	draw_mouse(sprite, game);
}

void	hall_draw(game_t *game, obj_t **sprite, engine_t *engine)
{
	draw_sprite(game, "resto", sprite);
	client_draw(game, engine);
	draw_sprite(game, "table", sprite);
	for (int i = 0; i < 5; i++) {
		if (engine->client[i].in_place == 1) {
			sfRenderWindow_drawSprite(game->window,
			engine->client[i].button[0], NULL);
			sfRenderWindow_drawSprite(game->window,
			engine->client[i].button[1], NULL);
		}
		if (engine->client[i].in_place == 1)
			tray_draw(game, engine, sprite, i);
	}
	selection_draw(game, sprite, engine);
	wish_draw(game, engine, sprite);
	panel_draw(game, sprite);
	draw_sprite(game, "light", sprite);
	ui_hall_draw(game, sprite, engine);
	draw_mouse(sprite, game);
}

void 	menu_draw(game_t *game, obj_t **sprite)
{
	sfRenderWindow_clear(game->window, sfWhite);
	parralax_right(sprite[search_obj_by_name(sprite, "city")],
	game->window, 0.6);
	draw_sprite(game, "menu", sprite);
	draw_sprite(game, "play", sprite);
	draw_sprite(game, "highscore", sprite);
	draw_sprite(game, "settings", sprite);
	draw_sprite(game, "quit", sprite);
	draw_mouse(sprite, game);
}
