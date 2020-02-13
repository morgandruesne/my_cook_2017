##
## EPITECH PROJECT, 2017
## makefile
## File description:
## c
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-L ../.graphic_programming/lib/ -I ../.graph_programming/include/SFML/

CFLAGS	+=	-I ./include/

LIB	=	-lm -lc_graph_prog

NAME	=	my_cook

SRC	=	cook.c				\
		pars_xml.c			\
		draw_client_relative.c 		\
		draw_ui.c 			\
		draw_hall.c 		\
		draw_ingredients.c 		\
		scene_loop.c 			\
		scene_event.c 			\
		scene_draw.c 			\
		scene_change.c 			\
		animation_menu.c 		\
		animation_client.c 		\
		animation_transition.c 	\
		sys_mouse.c			\
		add_files.c			\
		search_obj.c			\
		shortcuts.c			\
		setup.c 			\
		library_functions.c		\
		engine_client.c			\
		engine_time.c 			\
		engine_client_wish.c		\
		fill_tray.c			\
		engine_reset.c			\
		engine_money.c			\
		engine_hightscore.c		\
		get_next_line.c			\
		hitbox_kitchen.c		\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	export LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export LD_LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export CPATH=$CPATH:/home/charlieono/.graph_programming/include
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
