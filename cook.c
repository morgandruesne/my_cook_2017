/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** Description
*/

#include "cook.h"

void 	scene_handling(game_t *game, obj_t **sprite, engine_t *engine)
{
	static int 	actual_scene = 1;

	if (actual_scene != game->state.change_scene) {
		actual_scene = game->state.change_scene;
		game->state.anim[2] = 1;
	}
	menu_loop(game, sprite, engine);
	hall_loop(game, sprite, engine);
	pause_loop(game, sprite);
	kitchen_loop(game, sprite, engine);
	highscore_loop(game, sprite);
	change_scene(game, actual_scene);
	sfRenderWindow_display(game->window);
}

int	main(int ac, char **av, char **env)
{
	game_t	*game = malloc(sizeof(game_t));
	obj_t	**sprite = get_struct_from_xml();
	engine_t *engine = malloc(sizeof(engine_t));

	if (env == NULL || env[0] == NULL)
		return (84);
	(void)ac;
	(void)av;
	setup(game, sprite, engine);
	while (sfRenderWindow_isOpen(game->window))
		scene_handling(game, sprite, engine);
	return (0);
}
