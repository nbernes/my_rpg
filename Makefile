##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile our projects
##

NAME	=	my_rpg

SRC_DIR	=	./src/

BUTTON_DIR	=	./src/manage_button/

OBJECT_DIR	=	./src/manage_object/

UTILS_DIR	=	./src/utils/

EVENT_DIR	=	./src/event/

SCENE_DIR	=	./src/scenes/

MAP_DIR		=	./src/maps/

FIGHT_DIR	=	./src/fights/

END_DIR		=	./src/end/

SRC	=	$(SRC_DIR)main.c			\
		$(SRC_DIR)global.c			\
		$(SRC_DIR)prepare_gameplay.c		\
		$(SRC_DIR)launch_game.c			\
		$(SRC_DIR)check.c			\
		$(SRC_DIR)particles_leaf.c		\
		$(SRC_DIR)free_particles.c		\
		$(BUTTON_DIR)buttoninitialise.c		\
		$(BUTTON_DIR)buttonisclicked.c		\
		$(OBJECT_DIR)create_object.c		\
		$(OBJECT_DIR)destroy_object.c		\
		$(UTILS_DIR)check_env.c			\
		$(UTILS_DIR)create_window.c		\
		$(UTILS_DIR)check_create.c		\
		$(UTILS_DIR)destroy_struct.c		\
		$(UTILS_DIR)start_game_explain.c	\
		$(UTILS_DIR)int_to_string.c		\
		$(EVENT_DIR)manage_introduction.c	\
		$(EVENT_DIR)play_introduction.c		\
		$(EVENT_DIR)display_introduction.c	\
		$(EVENT_DIR)analyse_event.c		\
		$(EVENT_DIR)event_start.c		\
		$(EVENT_DIR)event_credits.c		\
		$(EVENT_DIR)event_explain.c		\
		$(EVENT_DIR)event_game.c		\
		$(EVENT_DIR)event_lose.c		\
		$(EVENT_DIR)event_parameters.c		\
		$(EVENT_DIR)event_pause.c		\
		$(EVENT_DIR)event_win.c			\
		$(EVENT_DIR)interface_event.c 		\
		$(EVENT_DIR)move_character.c		\
		$(EVENT_DIR)check_if_obst.c 		\
		$(EVENT_DIR)test_character_moves.c	\
		$(EVENT_DIR)calc_heron.c		\
		$(EVENT_DIR)calc_area.c			\
		$(EVENT_DIR)prepare_sprites_intro.c	\
		$(EVENT_DIR)hud_event.c			\
		$(EVENT_DIR)find_increment.c		\
		$(EVENT_DIR)event_quest.c		\
		$(EVENT_DIR)launch_fight.c		\
		$(EVENT_DIR)free_stats_player.c		\
		$(EVENT_DIR)victory_screen.c		\
		$(EVENT_DIR)victory_music_management.c	\
		$(SCENE_DIR)check_create_text.c		\
		$(SCENE_DIR)display_scene.c		\
		$(SCENE_DIR)display.c			\
		$(SCENE_DIR)check_malloc_scene.c	\
		$(SCENE_DIR)prepare_scenes.c		\
		$(SCENE_DIR)prepare_start.c		\
		$(SCENE_DIR)set_start.c			\
		$(SCENE_DIR)prepare_pause.c		\
		$(SCENE_DIR)set_pause.c			\
		$(SCENE_DIR)prepare_win.c		\
		$(SCENE_DIR)set_win.c			\
		$(SCENE_DIR)prepare_lose.c		\
		$(SCENE_DIR)set_lose.c			\
		$(SCENE_DIR)prepare_credits.c		\
		$(SCENE_DIR)prepare_explain.c		\
		$(SCENE_DIR)prepare_parameters.c	\
		$(SCENE_DIR)prepare_game.c		\
		$(SCENE_DIR)prepare_quest.c		\
		$(SCENE_DIR)text_creation.c		\
		$(SCENE_DIR)check_if_behind_obst.c	\
		$(SCENE_DIR)check_if_behind_stage.c	\
		$(SCENE_DIR)check_disp.c		\
		$(MAP_DIR)project_iso_point.c		\
		$(MAP_DIR)create_map.c			\
		$(MAP_DIR)draw_map.c			\
		$(MAP_DIR)set_tiles.c			\
		$(MAP_DIR)unset_map_objects.c		\
		$(MAP_DIR)display_map.c			\
		$(MAP_DIR)set_garden.c			\
		$(MAP_DIR)set_pantry_walls.c		\
		$(MAP_DIR)check_if_object.c		\
		$(MAP_DIR)switch_maps.c			\
		$(MAP_DIR)reset_character_pos.c		\
		$(MAP_DIR)set_pantry.c			\
		$(MAP_DIR)set_frontyard.c		\
		$(MAP_DIR)set_pnj.c			\
		$(MAP_DIR)draw_moving_sprites.c		\
		$(MAP_DIR)set_other_pantryobjects.c	\
		$(FIGHT_DIR)myrand.c			\
		$(FIGHT_DIR)fight.c			\
		$(FIGHT_DIR)free_fcts.c			\
		$(FIGHT_DIR)manage_fight_events.c	\
		$(FIGHT_DIR)prepare_menus.c		\
		$(FIGHT_DIR)set_options.c		\
		$(FIGHT_DIR)free_fight_menus.c		\
		$(FIGHT_DIR)draw_fight_fcts.c		\
		$(FIGHT_DIR)mouse_selection.c		\
		$(FIGHT_DIR)create_fight_container.c	\
		$(FIGHT_DIR)manage_blood.c		\
		$(FIGHT_DIR)draw_fight_scene.c		\
		$(FIGHT_DIR)free_instructions.c		\
		$(FIGHT_DIR)int_to_str.c		\
		$(FIGHT_DIR)draw_battle_index.c		\
		$(FIGHT_DIR)attack_ennemy.c		\
		$(FIGHT_DIR)run_potato.c		\
		$(FIGHT_DIR)create_ennemy.c		\
		$(FIGHT_DIR)print_life.c		\
		$(FIGHT_DIR)set_background.c		\
		$(FIGHT_DIR)defend_ennemy.c		\
		$(END_DIR)end.c				\
		$(END_DIR)free_parallax.c		\
		$(END_DIR)init_end_fcts.c		\
		$(END_DIR)start_go_music.c		\
		$(END_DIR)updates_fcts.c		\

CFLAGS	=	-W -Wall -Wextra -I ./include -I ./include/printf

OBJ	=	$(SRC:%.c=%.o)

LIB	=	-L ./lib/my -lmy -l c_graph_prog -lm

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/my/
		unzip ressource.zip
		$(CC) -o $(NAME) $(OBJ) $(LIB)
		@echo "COMPILATION COMPLETED"

gclean:
		$(RM) *.gc*
		rm -rf ressource

clean:
		rm -f $(OBJ)
		rm -rf ressource

fclean:		clean
		rm -f $(NAME)
		$(MAKE) clean -C ./lib/my
		@echo "CLEAR COMPLETED"

re:		fclean all

tests_run:
		unzip ressource.zip
		$(MAKE) -C ./tests gclean
		$(MAKE) -C ./tests
		./tests/test --verbose
		cp ./tests/*.gcno .
		$(MAKE) -C ./tests gclean

debug:		CFLAGS += -g
debug:		re
