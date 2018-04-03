/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** choose_ingredients
*/

#include "proto.h"

void choose_other_ingredients(int value, scene_t *game_scene, int ord, int ing)
{
	switch (value) {
	case sfKeyR:
		game_scene[GAME].player->ingredients[ord][ing] = 'R';
		break;
	case sfKeyT:
		game_scene[GAME].player->ingredients[ord][ing] = 'T';
		break;
	case sfKeyY:
		game_scene[GAME].player->ingredients[ord][ing] = 'Y';
		break;
	case sfKeyU:
		game_scene[GAME].player->ingredients[ord][ing] = 'U';
		break;
	default:
		return;
	}
}

void choose_ingredients(sfEvent *event, scene_t *game_scene, int ord, int *ing)
{
	int value = 0;

	if (event->type == sfEvtKeyPressed) {
		value = event->key.code;
		switch (value) {
		case sfKeyA:
			game_scene[GAME].player->ingredients[ord][*ing] = 'A';
			break;
		case sfKeyZ:
			game_scene[GAME].player->ingredients[ord][*ing] = 'Z';
			break;
		case sfKeyE:
			game_scene[GAME].player->ingredients[ord][*ing] = 'E';
			break;
		default:
			choose_other_ingredients(value, game_scene, ord, *ing);
		}
	}
	if (game_scene[GAME].player->ingredients[ord][*ing] != 'X')
		*ing += 1;
}
