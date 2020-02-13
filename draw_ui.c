/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** draw ui functions
*/

#include "cook.h"

void	ui_time_draw(game_t *game, engine_t *engine, sfText *txt)
{
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setString(txt, "Time left:");
	sfText_setPosition(txt, (sfVector2f) {320, 995});
	sfRenderWindow_drawText(game->window, txt, NULL);
	sfText_setColor(txt, (sfColor) {0, 201, 255, 255});
	sfText_setString(txt, my_getchar(engine->time));
	if (engine->time < 0)
		sfText_setString(txt, "0");
	sfText_setPosition(txt, (sfVector2f) {500, 995});
	sfRenderWindow_drawText(game->window, txt, NULL);
}

void	ui_money_draw(game_t *game, engine_t *engine, sfText *txt)
{
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setString(txt, "Money:");
	sfText_setPosition(txt, (sfVector2f) {600, 995});
	sfRenderWindow_drawText(game->window, txt, NULL);
	sfText_setColor(txt, (sfColor) {35, 255, 0, 255});
	sfText_setString(txt, my_getchar(engine->money));
	if (engine->money < 0)
		sfText_setString(txt, "0");
	sfText_setPosition(txt, (sfVector2f) {738, 995});
	sfRenderWindow_drawText(game->window, txt, NULL);
}

void	ui_hall_draw(game_t *game, obj_t **sprite, engine_t *engine)
{
	static sfRectangleShape *bg = NULL;
	static sfFont 	*font = NULL;
	sfText 		*txt;

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfRectangleShape_setSize(bg, (sfVector2f) {1980, 150});
	sfRectangleShape_setFillColor(bg, (sfColor) {0, 0, 0, 127});
	sfRectangleShape_setPosition(bg, (sfVector2f) {0, 970});
	sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	ui_time_draw(game, engine, txt);
	ui_money_draw(game, engine, txt);
	hover_buttons(game, sprite);
	set_pos(sprite, "pause", (sfVector2f) {10, 970});
	draw_sprite(game, "pause", sprite);
}

void	ui_ingredients_draw(game_t *game, obj_t **sprite)
{
	static sfRectangleShape *bg = NULL;
	sfVector2f pos = (sfVector2f) {1300, 100};

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {650, 830});
	sfRectangleShape_setFillColor(bg, (sfColor) {0, 0, 0, 127});
	sfRectangleShape_setPosition(bg, (sfVector2f) {1230, 50});
	sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
	for (int i = 1; i <= NB_INGREDIENT; i++) {
		select_ingredient(sprite, i);
		sfSprite_setPosition(sprite[21]->obj, pos);
		set_scale(sprite, "burger", (sfVector2f) {3, 3});
		draw_sprite(game, "burger", sprite);
		pos.x += 175;
		if (i % 3 == 0) {
			pos.y += 175;
			pos.x = 1300;
		}
	}
}