/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** all proto of project
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "scene.h"
#include "my.h"
#include "fight.h"

#ifndef __PROTO_H_
#define __PROTO_H_

typedef struct {
	sfSprite *chara;
	sfTexture *text;
	sfIntRect rect;
	sfVector2f position;
} player_t;

/* GLOBAL */

extern const int ERROR;
extern const int OK;
extern const int WIN_HEIGHT;
extern const int WIN_WIDTH;
extern const int OFFSET;
extern const int MAX_PART_BLOOD;
extern const int MAX_PART_LEAF;

/* GAME */

int prepare_gameplay(void);
int launch_game(sfRenderWindow*, scene_t *);
void move_background(int, int , game_object_t *);
int fill_sparkle(scene_t *);
int check_actual(type_scene_t, bool *, sfRenderWindow*, sfEvent *);
int alloc_quest(scene_t *);
void create_hero_text(scene_t *);
void draw_particles_leaf(sfRenderWindow*, particles_t *);
particles_t *init_particles_leaf(char *);
int fight(sfRenderWindow *, actor_t *, int);
void free_game_data(particles_t *, sfClock *);
void end(sfRenderWindow *, scene_t *);

/* UTILS */

int check_env(char **);
sfRenderWindow* create_window(void);
int check_create(sfRenderWindow**, scene_t **);
void destroy_struct(scene_t *);
int start_game_explain(sfRenderWindow*, sfEvent *);
char *int_to_string(int);
double myrand(double, double);

/* EVENT */

int analyse_event(sfRenderWindow*, sfEvent *, scene_t*, type_scene_t *);
void event_start(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_credits(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_explain(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_lose(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_parameters(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_pause(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_win(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void event_game(sfEvent *, type_scene_t *, scene_t *);
void move_left(scene_t*);
void move_right(scene_t*);
void move_down(scene_t*);
void move_up(scene_t*);
void manage_introduction(sfRenderWindow*, sfEvent *, bool *);
game_object_t *prepare_potato(void);
game_object_t *prepare_carrot(void);
game_object_t *prepare_ant(void);
void interface_events(scene_t *, sfEvent *);
void interface_event(scene_t *, sfEvent *);
void test_character_moves(scene_t *, float, float);
int check_if_obst(sfVector3f **, sfVector2f, type_stage_t);
int identify_which_tile(sfVector3f **, sfVector2i, sfVector2f, int);
float calc_tri_ar(sfVector3f, sfVector3f, sfVector2f);
float calc_kite_ar(float, float);
float pytha(float, float, float, float);
float calc_heron(float, float, float);
int identify_obst_size(sfVector3f **, sfVector2i, sfVector2f, type_stage_t);
int get_obj_boundaries(sfVector3f **, sfVector2f, type_stage_t);
int manage_pantry_bounds(sfVector3f **, sfVector2f, type_stage_t);
int calc_exit_bounds(sfVector3f **, sfVector2f);
int play_int(sfRenderWindow*, sfEvent *);
int display_introduction(sfRenderWindow*, game_object_t **);
int verify_creation_of_text(sfFont**, sfText**);
void hud_displaying_event(scene_t *, sfEvent *);
int find_increment(int, type_stage_t);
int find_pantry_incr(int);
int find_garden_incr(int);
void check_event_search(scene_t *, sfEvent *);
int launch_fight(sfRenderWindow*, scene_t *, type_scene_t);
int evaluate_pantry_pos(sfRenderWindow*, scene_t *, type_scene_t);
int evaluate_frontyard_pos(sfRenderWindow*, scene_t *, type_scene_t);
void move_rect(scene_t *, int, int);
void check_pnj_talks(scene_t *, sfEvent *);
void display_victory(scene_t *, sfRenderWindow *, sfEvent *);
void start_music(scene_t *);
void stop_music(scene_t *);

/* SCENES */

int check_create_text(int, scene_t *);
int check_malloc_scene(scene_t *);
int prepare_scenes(scene_t *);
int prepare_start(scene_t *);
void set_string_start(scene_t *);
void set_origin_start(scene_t *);
int prepare_pause(scene_t *);
void set_string_pause(scene_t *);
void set_origin_pause(scene_t *);
int prepare_win(scene_t *);
void set_string_win(scene_t *);
void set_origin_win(scene_t *);
int prepare_lose(scene_t *);
void set_string_lose(scene_t *);
void set_origin_lose(scene_t *);
int prepare_game(scene_t *);
int prepare_credits(scene_t *);
int prepare_explain(scene_t *);
int prepare_parameters(scene_t *);
void display_scene(sfRenderWindow*, scene_t *, type_scene_t *, type_scene_t);
int display(scene_t *, sfRenderWindow*, type_scene_t);
void check_disp(scene_t *, sfRenderWindow*, int);
void display_others_things(scene_t *, sfRenderWindow*);
void check_if_behind_obst(sfRenderWindow*, scene_t *, \
sfVector2i *, sfVector2f);
int go_through_each_obst(sfRenderWindow*, sfVector2f, scene_t *);
void compare_h_to_small_obj(sfRenderWindow*, scene_t *, \
sfVector2i *, sfVector2f);
void compare_h_to_medium_obj(sfRenderWindow*, scene_t *, \
sfVector2f, sfVector2i *);
void compare_h_to_big_obj(sfRenderWindow*, scene_t *, \
sfVector2f, sfVector2i *);
void check_if_behind_garden(sfRenderWindow*, scene_t *, \
sfVector2i *, sfVector2f);
void check_if_behind_pantry(sfRenderWindow*, scene_t *, \
sfVector2i *, sfVector2f);
void check_if_behind_frontyard(sfRenderWindow*, scene_t *, \
sfVector2i *, sfVector2f);
int create_quest_text(scene_t *);
void create_quest_objects(scene_t *);
void free_stats(char *, char *, char *, char *);
void free_stats_others(char *, char *);
void check_disp(scene_t *, sfRenderWindow*, int);

/* MAPS */

sfVector3f **assign_map(sfVector3f **);
sfVector3f **create_map(void);
sfVector3f **change_map(sfVector3f **, const char *, type_stage_t, boolbis_t *);
int create_map_caption(sfRenderWindow*, scene_t *);
int draw_caption(sfRenderWindow*);
sfVector2f project_iso_point(int, int);
sfIntRect set_random_rect(void);
sfVector3f **write_down_small_obst(sfVector3f **, sfVector2f *);
int compare_positions(sfVector3f, sfVector2f *);
void unset_objects(sfVector3f **);
sfRenderWindow* set_bush(sfRenderWindow*, sfVector2f, int);
sfRenderWindow* set_tree(sfRenderWindow*, sfVector2f);
int read_file(const char *, sfVector3f **);
int write_file_contents(char *, sfVector3f **, int);
sfRenderWindow*display_each_object(sfRenderWindow*, sfVector3f **, \
sfVector2i *, type_stage_t *);
sfRenderWindow*draw_map(sfVector3f **, sfRenderWindow*, type_stage_t);
sfRenderWindow*display_each_row(sfRenderWindow*, sfVector3f **, \
sfVector2i *, type_stage_t);
int switch_maps(sfVector3f **, sfVector2f, type_stage_t, boolbis_t *);
void reset_character_pos(sfVector2f *);
type_stage_t change_stage(float, type_stage_t);
int reset_flag(sfVector3f **, sfVector2f);
sfRenderWindow*set_pear(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_fence(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_tiles(sfRenderWindow*, sfVector3f **, \
sfVector2i *, type_stage_t);
sfRenderWindow*set_each_tile(sfRenderWindow*, tile_t *, \
type_stage_t, sfVector2i *);
sfTexture *choose_tile_texture(sfTexture *, sfVector2i *, type_stage_t);
sfTexture *set_grass_texture(void);
sfRenderWindow*check_if_object(sfVector3f **, sfRenderWindow*, sfVector2i *, \
type_stage_t *);
sfRenderWindow*set_pantry_wall_r(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_pantry_wall_l(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_pantry_bot_r(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_pantry_bot_l(sfRenderWindow*, sfVector2f);
sfRenderWindow*set_garden_objects(sfRenderWindow*, sfVector2f, float);
sfRenderWindow*set_frontyard_objects(sfRenderWindow*, sfVector2f, float);
sfRenderWindow*set_pantry_objects(sfRenderWindow*, sfVector2f, \
sfVector2i *, float);
sfRenderWindow* set_human(sfRenderWindow*, sfVector2f, char *);
sfRenderWindow* set_chips_bowl(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_picnic_table(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_trunk(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_lamp(sfRenderWindow*, sfVector2f);
sfRenderWindow* draw_moving_sprites(sfVector3f **, sfRenderWindow*, \
type_stage_t, sfClock *);
sfRenderWindow* draw_pnj(sfVector3f **, sfRenderWindow*, sfVector2i *, \
sfClock *);
int update_from_clock(sfClock *, int);
sfRenderWindow* set_mushroom(sfRenderWindow*, sfVector2f, sfClock *);
void unset_double_arr(char **);
int manage_flag(sfRenderWindow*, scene_t *);
sfRenderWindow* set_potato_bag(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_boxes(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_dog(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_carrot(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_fridge(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_shelf(sfRenderWindow*, sfVector2f);
sfRenderWindow* set_drawer(sfRenderWindow*, sfVector2f);

#endif
