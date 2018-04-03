/*
** EPITECH PROJECT, 2017
** proto
** File description:
** all proto of programs
*/

#ifndef __PROTO_H_
#define __PROTO_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "game_object.h"
#include "recipes.h"
#include "scene.h"
#include "my.h"

extern const int offset;
extern const int error;
extern const int window_height;
extern const int window_width;
extern const int check_diff;

int check_env(char **);
int launch_game(sfRenderWindow*, scene_t *, sfClock *);
int check_create(sfRenderWindow **, scene_t **, sfClock *);
sfRenderWindow* create_window(void);
void analyse_event(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
int prepare_scenes(scene_t *);
int prepare_start(scene_t *);
int prepare_pause(scene_t *);
int prepare_credits(scene_t *);
int prepare_explain(scene_t *);
int prepare_parameters(scene_t *);
int prepare_game(scene_t *);
int prepare_win(scene_t *);
int prepare_lose(scene_t *);
int check_malloc_scene(scene_t *);
void free_all(scene_t **);
int display_scene(scene_t, sfRenderWindow*, sfClock *);
void set_origin_start(scene_t *);
void set_string_start(scene_t *);
void set_origin_pause(scene_t *);
void set_string_pause(scene_t *);
void set_origin_game(scene_t *);
void set_string_game(scene_t *);
void set_origin_win(scene_t *);
void set_string_win(scene_t *);
void set_origin_lose(scene_t *);
void set_string_lose(scene_t *);
int check_create_text(int, scene_t *);
void manage_event_start(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void manage_event_win(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void manage_event_lose(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
void manage_event_parameters(sfEvent *, scene_t *, type_scene_t *);
void manage_event_credits(sfEvent *, scene_t *, type_scene_t *);
void manage_event_explain(sfEvent *, scene_t *, type_scene_t *);
void manage_event_game(sfEvent *, scene_t *, type_scene_t *);
void manage_event_pause(sfRenderWindow*, sfEvent *, scene_t *, type_scene_t *);
int init_player_struct(scene_t *);
int check_order_nbr(sfEvent *, int, scene_t *);
int check_if_right_ing(scene_t *, int );
void change_value_actual(type_scene_t *, type_scene_t);
int buttonisclicked(button_t *, sfVector2f);
int buttoninitialise(button_t *);
void display_choose(scene_t *, sfRenderWindow*);
int manage_objects_game(scene_t *);
int manage_customers(scene_t *);
void choose_ingredients(sfEvent *, scene_t *, int, int *);
char *int_to_string(int);
void send_customers(sfRenderWindow *, scene_t *);
char *change_time(int);
int manage_timer(scene_t, sfRenderWindow*, sfClock *);
int find_size(int);
int manage_money(scene_t, sfRenderWindow*);
void create_check_objs(scene_t *, int);
void reset_game(scene_t *);

#endif
