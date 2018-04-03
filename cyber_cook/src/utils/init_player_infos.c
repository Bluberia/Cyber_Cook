/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** init player info (time, money etc)
*/

#include "proto.h"

int init_player_ingredients_input(scene_t *game_scene)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 5; i++) {
		game_scene->player->ingredients[i] = malloc(sizeof(char) * 5);
		if (game_scene->player->ingredients[i] == NULL)
			return (error);
		for (j = 0; j < 4; j++)
			game_scene->player->ingredients[i][j] = 'X';
		game_scene->player->ingredients[i][j] = '\0';
	}
	game_scene->player->ingredients[i] = NULL;
	return (0);
}

int init_player_struct(scene_t *game_scene)
{
	game_scene->player = malloc(sizeof(player_t));
	if (game_scene->player == NULL)
		return (error);
	game_scene->player->money = 100;
	game_scene->player->time = 500;
	game_scene->player->ingredients = malloc(sizeof(char *) * 6);
	if (game_scene->player->ingredients == NULL)
		return (error);
	if (init_player_ingredients_input(game_scene) == error)
		return (error);
	game_scene->player->clock = sfClock_create();
	return (0);
}
