/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** game header with events, sounds and system data
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "game.h"
#include "graphics.h"
#include "engine.h"
#include "pars.h"

#define	NB_CLOCK		8
#define NB_ANIM			3
#define NB_INGREDIENT		8

/*
	scene : int qui renvoie à la scène actuelle.
	anime_menu : bool qui appelle l'animation du menu (défilement)
*/

typedef struct state_s {
	int		scene;
	int 	side;
	int		*anim;
	int 	change_scene;
} state_t;

typedef struct game_s {
	sfClock 	**clock;
	sfRenderWindow	*window;
	sfEvent 	event;
	struct state_s	state;
	int 		*higtscore;
	sfVector2i	pos_mouse;
} game_t;

//	Setup Functions
void	setup(game_t *game, obj_t **sprite, engine_t *engine);

//	Relative to mouse
void	draw_mouse(obj_t **sprite, game_t *game);
int 	mouse_is_hover(sfSprite *elem, sfVector2i pos_click);
int	sprite_is_clicked(sfSprite *elem, sfVector2i pos_click, double scale);
void	hover_buttons(game_t *game, obj_t **sprite);

//	Events
void 	menu_events(game_t *game);
void	hall_events(game_t *game, engine_t *engine, obj_t **sprite);
void	kitchen_events(game_t *game, engine_t *engine);
void	hall_interactions(game_t *game, engine_t *engine);
void	panel_interactions(game_t *game, engine_t *engine, obj_t **sprite);

//	Animations
void	animation_menu(game_t *game, obj_t **sprite);
void	animation_hall(game_t *game, obj_t **sprite);
void	animation_client_arrival(engine_t *engine, game_t *game);
void	animation_client_waiting(engine_t *engine, game_t *game);
void	animation_client_departure(engine_t *engine, game_t *game);
void 	parralax_right(obj_t *sprite, sfRenderWindow *window, float speed);

//	Basic Functions
int	my_strlen(char const *str);
int	my_strcmp(char *str, char *str2);
int 	my_getnbr(char *str);
char	*my_getchar(int nbr);

//	Scene Handling
void	menu_change(game_t *game, obj_t **sprite, engine_t *engine);
void	hall_change(game_t *game, obj_t **sprite, engine_t *engine);
void	pause_change(game_t *game, obj_t **sprite);
void	highscore_change(game_t *game, obj_t **sprite);
void 	scene_handling(game_t *game, obj_t **sprite, engine_t *engine);
void	change_scene(game_t *game, int scene);
void 	menu_loop(game_t *game, obj_t **sprite, engine_t *engine);
void	kitchen_loop(game_t *game, obj_t **sprite, engine_t *engine);
void	hall_loop(game_t *game, obj_t **sprite, engine_t *engine);
void	pause_loop(game_t *game, obj_t **sprite);
void	highscore_loop(game_t *game, obj_t **sprite);

//	Draw Objects
void 	menu_draw(game_t *game, obj_t **sprite);
void	hall_draw(game_t *game, obj_t **sprite, engine_t *engine);
void	pause_draw(game_t *game, obj_t **sprite);
void	kitchen_draw(game_t *game, obj_t **sprite, engine_t *engine);
void	highscore_draw(game_t *game, obj_t **sprite);
void	ui_hall_draw(game_t *game, obj_t **sprite, engine_t *engine);
void	ui_ingredients_draw(game_t *game, obj_t **sprite);
void	panel_draw(game_t *game, obj_t **sprite);
void	tray_draw(game_t *game, engine_t *engine, obj_t **sprite, int i);
void	wish_draw(game_t *game, engine_t *engine, obj_t **sprite);
void	selection_draw(game_t *game, obj_t **sprite, engine_t *engine);
void	client_draw(game_t *game, engine_t *engine);
void	set_position_client_buttons(engine_t *engine);
void	select_ingredient(obj_t **sprite, int id);
void	draw_burger(game_t *game, obj_t **sprite, char *tray, int infos[2]);
void	draw_burger_m(game_t *game, obj_t **sprite, char *tray, int infos[2]);
void	draw_wish_burger(game_t *game, obj_t **sprite, char *tray);

//	File handling - .morly
obj_t	**get_struct_from_xml(void);
obj_t	*get_all_param(char *str);
char	*get_files(char const *filepath);

//	Search objects by names - change parameters - shortcuts.
void	set_scale(obj_t **sprite, char *str, sfVector2f scale);
void	set_pos(obj_t **sprit, char *str, sfVector2f pos);
void	draw_sprite(game_t *game, char *str, obj_t **sprite);
int	search_obj_by_name(obj_t **sprite, char *str);

char	*concat(char *dest, char *src);

void	get_wish_client(engine_t *engine, int select);
char	*fill_tray(engine_t *engine, char c, char *tray, int i);
int 	get_supp(char *str, char c);
void	get_client(game_t *game, engine_t *engine);
void	format_tray_command(engine_t *engine);

void	reset_actual_tray(engine_t *engine, int i);
char	*reset_burger(char *str);
void	reset_engine(game_t *game, engine_t *engine, obj_t **sprite);
void	engine_time(game_t *game, engine_t *engine);
void	format_tray_command(engine_t *engine);

char	*my_get_next_line(int fd);

int	get_all_hit_box(sfVector2i mause, game_t *game, engine_t *engine);
int test_hit(sfVector2i top, sfVector2i bot, sfVector2i mause);
int	*get_hightscore(void);

int	*put_in_higtscore(int tab[10], int nb);
void	write_hightscore(int *tab);

#endif
