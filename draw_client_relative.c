/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** all draw functions relative to clients
*/

#include "cook.h"

void	set_position_client_buttons(engine_t *engine)
{
	int 		pos[5] = {120, 470, 820, 1170, 1520};
	sfVector2f	in = (sfVector2f) {0, 700};
	sfVector2f	out = (sfVector2f) {-200, -200};
	sfVector2f	final;

	for (int i = 0; i < 5; i++) {
		final.x = (engine->client[i].in_place) ? pos[i] + 95 : out.x;
		final.y = (engine->client[i].in_place) ? in.y : out.y;
		sfSprite_setPosition(engine->client[i].button[0], final);
		final.x += 50;
		final.y -= 5;
		sfSprite_setPosition(engine->client[i].button[1], final);
	}
}

void	client_draw(game_t *game, engine_t *engine)
{
	set_position_client_buttons(engine);
	for (int i = 0; i < 5; i++) {
		if (engine->client[i].walking == 1) {
			sfRenderWindow_drawSprite(game->window,
			engine->client[i].obj, NULL);
		}
		if (engine->client[i].walking == 2) {
			sfRenderWindow_drawSprite(game->window,
			engine->client[i].obj, NULL);
		}
	}
	for (int i = 0; i < 5; i++) {
		if (engine->client[i].in_place == 1) {
			sfRenderWindow_drawSprite(game->window,
			engine->client[i].obj, NULL);
		}
	}
}

void	selection_null_draw(game_t *game, engine_t *engine)
{
	static sfFont 	*font = NULL;
	sfText 	*txt;
	static sfRectangleShape *bg = NULL;

	if (engine->select != -1)
		return;
	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {400, 100});
	sfRectangleShape_setFillColor(bg, (sfColor) {0, 0, 0, 127});
	sfRectangleShape_setPosition(bg, (sfVector2f) {730, 280});
	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setString(txt, "Select a customer!");
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setPosition(txt, (sfVector2f) {750, 300});
	sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
	sfRenderWindow_drawText(game->window, txt, NULL);
}

void	selection_draw(game_t *game, obj_t **sprite, engine_t *engine)
{
	int 		pos[5] = {130, 480, 830, 1180, 1530};
	sfVector2f	pos2;

	for (int i = 0; i < 5; i++) {
		if (i == engine->select && engine->client[i].in_place == 1) {
			pos2.x = pos[i] - 100;
			pos2.y = 260;
			set_pos(sprite, "select", pos2);
			draw_sprite(game, "select", sprite);
		}
	}
	selection_null_draw(game, engine);
}