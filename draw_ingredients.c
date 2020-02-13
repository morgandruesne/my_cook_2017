/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** draw functions relative to ingredients (wish, tray, burger..)
*/

#include "cook.h"

void	select_ingredient(obj_t **sprite, int id)
{
	int 	offset = id * 50 - 50;
	sfIntRect rect = (sfIntRect) {offset, 0, 50, 50};

	sfSprite_setTextureRect(sprite[21]->obj, rect);
}

void	draw_burger_m(game_t *game, obj_t **sprite, char *tray, int infos[2])
{
	int 	ingredient = 0;
	sfVector2f pos = {infos[0], infos[1]};

	for (int i = 2; i < 9; i++) {
		ingredient = tray[i] - '0';
		select_ingredient(sprite, ingredient);
		pos.y -= 7;
		set_scale(sprite, "burger", (sfVector2f) {3, 3});
		set_pos(sprite, "burger", pos);
		draw_sprite(game, "burger", sprite);
	}
}

void	draw_burger(game_t *game, obj_t **sprite, char *tray, int infos[2])
{
	int 	ingredient = 0;
	sfVector2f pos = {infos[0], infos[1]};

	for (int i = 2; i < 9; i++) {
		ingredient = tray[i] - '0';
		select_ingredient(sprite, ingredient);
		pos.y -= 14;
		set_scale(sprite, "burger", (sfVector2f) {6, 6});
		set_pos(sprite, "burger", pos);
		draw_sprite(game, "burger", sprite);
	}
}

void	wish_burger_text(game_t *game)
{
	static sfFont 	*font = NULL;
	sfText 		*txt;

	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setString(txt, "Actual command");
	sfText_setPosition(txt, (sfVector2f) {227, 100});
	sfRenderWindow_drawText(game->window, txt, NULL);
}

void	draw_wish_burger(game_t *game, obj_t **sprite, char *tray)
{
	int 	ingredient = 0;
	sfVector2f pos = {90, 150};
	static sfRectangleShape *bg = NULL;

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {910, 250});
	sfRectangleShape_setFillColor(bg, (sfColor) {0, 0, 0, 127});
	sfRectangleShape_setPosition(bg, (sfVector2f) {160, 80});
	sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
	wish_burger_text(game);
	for (int i = 2; i < 9; i++) {
		ingredient = tray[i] - '0';
		select_ingredient(sprite, ingredient);
		pos.x += 110;
		set_scale(sprite, "burger", (sfVector2f) {3, 3});
		set_pos(sprite, "burger", pos);
		draw_sprite(game, "burger", sprite);
	}
}