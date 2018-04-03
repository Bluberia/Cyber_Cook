##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile our projects
##

NAME	=	my_cook

SRC_DIR	=	./src/

OBJECT_DIR	=	./src/manage_object/

BUTTON_DIR	=	./src/manage_button/

SCENE_DIR	=	./src/manage_scene/

UTILS_DIR	=	./src/utils/

EVENT_DIR	=	./src/event/

SRC   	 =	$(SRC_DIR)global.c				\
		$(SRC_DIR)main.c				\
		$(SRC_DIR)launch_game.c				\
		$(BUTTON_DIR)buttoninitialise.c			\
		$(BUTTON_DIR)buttonisclicked.c			\
		$(OBJECT_DIR)create_object.c		    	\
                $(OBJECT_DIR)destroy_object.c			\
		$(SCENE_DIR)prepare_scenes.c			\
		$(SCENE_DIR)prepare_start.c			\
		$(SCENE_DIR)set_start.c				\
		$(SCENE_DIR)prepare_pause.c			\
		$(SCENE_DIR)set_pause.c				\
		$(SCENE_DIR)prepare_win.c			\
		$(SCENE_DIR)set_win.c				\
		$(SCENE_DIR)prepare_lose.c			\
		$(SCENE_DIR)set_lose.c				\
		$(SCENE_DIR)prepare_credits.c			\
		$(SCENE_DIR)prepare_explain.c			\
		$(SCENE_DIR)prepare_parameters.c		\
		$(SCENE_DIR)prepare_game.c			\
		$(SCENE_DIR)display_scene.c			\
		$(SCENE_DIR)prepare_objs_game.c			\
		$(SCENE_DIR)manage_timer.c			\
		$(SCENE_DIR)manage_money.c			\
		$(UTILS_DIR)check_env.c				\
		$(UTILS_DIR)init_player_infos.c			\
		$(UTILS_DIR)int_to_string.c			\
		$(UTILS_DIR)change_time.c			\
		$(UTILS_DIR)reset_game.c			\
		$(UTILS_DIR)create_window.c			\
		$(UTILS_DIR)change_value_actual.c		\
		$(EVENT_DIR)analyse_event.c			\
		$(EVENT_DIR)manage_event_start.c		\
		$(EVENT_DIR)manage_event_credits.c		\
		$(EVENT_DIR)manage_event_explain.c		\
		$(EVENT_DIR)manage_event_game.c			\
		$(EVENT_DIR)manage_event_win.c			\
		$(EVENT_DIR)manage_event_lose.c			\
		$(EVENT_DIR)manage_event_pause.c		\
		$(EVENT_DIR)manage_orders_event.c		\
		$(EVENT_DIR)manage_event_parameters.c		\
		$(EVENT_DIR)display_choose.c			\
		$(EVENT_DIR)choose_ingredients.c		\
		$(EVENT_DIR)manage_customers_event.c

CFLAGS	=	-W -Wall -Wextra -I ./include

OBJ	=	$(SRC:%.c=%.o)

LIB	=	-L ./lib/my -lmy -lm -l c_graph_prog

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/my/
		unzip ressource.zip
		$(CC) -o $(NAME) $(OBJ) $(LIB)
		@echo "COMPILATION COMPLETED"

clean:
		rm -f $(OBJ)
		rm -rf ressource

fclean:		clean
		rm -f $(NAME)
		$(MAKE) clean -C ./lib/my/
		@echo "CLEAR COMPLETED"

re:		fclean all

tests_run:
		$(MAKE) -C ./tests
		./tests/test
		$(MAKE) -C ./tests clean

debug:		CFLAGS += -g3
debug:		re
