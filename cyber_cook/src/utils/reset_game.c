/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** reset game
*/

#include "proto.h"

void reset_game(scene_t *game_scene)
{
	game_scene[GAME].player->money = 100;
	game_scene[GAME].player->time = 500;
	for (int i = 0; i < 5; i++)
		game_scene[GAME].customers[i]->position.x = 1650;
}
