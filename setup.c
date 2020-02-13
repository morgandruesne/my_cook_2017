/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** setup functions
*/

#include "cook.h"

sfRenderWindow 	*my_window_create(void)
{
	sfRenderWindow 	*window;
	sfVideoMode	mode;

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My Cook", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

obj_t	*create_object(const char *path, sfVector2f pos, sfIntRect rect)
{
	obj_t	*sprite = malloc(sizeof(obj_t));

	sprite->obj = sfSprite_create();
	sprite->pos = (sfVector2f) {pos.x, pos.y};
	sprite->img = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite->obj, sprite->img, sfTrue);
	sfSprite_setPosition(sprite->obj, pos);
	sfSprite_setTextureRect(sprite->obj, rect);
	return (sprite);
}

void 	setup_scale(obj_t **sprite)
{
	set_scale(sprite, "table", (sfVector2f){0.75, 0.75});
	set_scale(sprite, "panel", (sfVector2f){0.50, 0.50});
	set_scale(sprite, "bunny", (sfVector2f){6, 6});
	set_scale(sprite, "fries", (sfVector2f){3, 3});
	set_scale(sprite, "soda1", (sfVector2f){3, 3});
	set_scale(sprite, "soda2", (sfVector2f){3, 3});
	set_scale(sprite, "select", (sfVector2f){0.8, 0.8});
	set_scale(sprite, "city", (sfVector2f){2.86, 2.86});
	set_scale(sprite, "resto", (sfVector2f){4, 4});
	set_scale(sprite, "burger-view", (sfVector2f){3, 3});
	set_scale(sprite, "kitchen", (sfVector2f){2.67, 2.67});
	set_scale(sprite, "ketchup", (sfVector2f){5.27, 5.27});
	set_scale(sprite, "carrot", (sfVector2f){5.27, 5.27});
	set_scale(sprite, "button_cros", (sfVector2f){0.595, 0.595});
	set_scale(sprite, "button_valid", (sfVector2f){0.5, 0.5});
	set_scale(sprite, "back", (sfVector2f){0.5, 0.5});
}

void 	setup_engine(obj_t **sprite, engine_t *engine)
{
	sfSprite *bunny = sprite[search_obj_by_name(sprite, "bunny")]->obj;
	sfSprite *cross = sprite[search_obj_by_name(sprite,
	"button_cros")]->obj;
	sfSprite *valid = sprite[search_obj_by_name(sprite,
	"button_valid")]->obj;

	for (int i = 0; i < 5; i++) {
		engine->client[i].obj = sfSprite_copy(bunny);
		sfSprite_setScale(engine->client[i].obj, (sfVector2f){6, 6});
		engine->client[i].button[0] = sfSprite_copy(cross);
		engine->client[i].button[1] = sfSprite_copy(valid);
		sfSprite_setScale(engine->client[i].button[0], (sfVector2f)
		{0.2, 0.2});
		sfSprite_setScale(engine->client[i].button[1], (sfVector2f)
		{0.2, 0.2});
	}
}

void	setup(game_t *game, obj_t **sprite, engine_t *engine)
{
	game->window = my_window_create();
	game->clock = malloc(sizeof(sfClock*) * NB_CLOCK);
	for (int i = 0; i < NB_CLOCK; i++)
		game->clock[i] = sfClock_create();
	setup_engine(sprite, engine);
	game->state.anim = malloc(sizeof(int) * NB_ANIM);
	game->state.scene = 1;
	game->state.change_scene = 1;
	game->state.anim[0] = 1;
	game->state.anim[2] = 0;
	game->state.side = 0;
	engine->select = -1;
	engine->money = 0;
	engine->time = INIT_TIME;
	game->higtscore = get_hightscore();
	sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
	setup_scale(sprite);
}
