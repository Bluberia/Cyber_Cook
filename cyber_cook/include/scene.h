/*
** EPITECH PROJECT, 2018
** scene
** File description:
** scene
*/

#include "proto.h"

#ifndef __SCENE_H_
#define __SCENE_H_

enum e_type_scene
{
	START,
	PAUSE,
	CREDITS,
	EXPLAIN,
	PARAMETERS,
	GAME,
	WIN,
	LOSE,
	SCENE_SIZE,
};

typedef enum e_type_scene type_scene_t;

typedef struct s_player
{
	char **ingredients;
	int money;
	int time;
	sfClock *clock;
} player_t;

typedef struct s_text
{
	sfFont* font;
	sfText* text;
	sfVector2f pos_text;
} text_t;

typedef struct s_button
{
	sfRectangleShape *rect;
	sfVector2f position;
	sfVector2f size;
	void (*callback)(type_scene_t *, type_scene_t);
} button_t;

typedef struct s_scene
{
	game_object_t **customers;
	int nb_objects;
	game_object_t **objs;
	int nb_buttons;
	button_t **buttons;
	int nb_text;
	text_t **text;
	type_scene_t type;
	orders_t **orders;
	player_t *player;
	int state_music;
	sfMusic* music;
	int save_ord;
} scene_t;

#endif
