/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event game
*/

#include "proto.h"

int check_if_right_ing(scene_t *game_scene, int ord)
{
	if (my_strcmp(game_scene[GAME].orders[ord]->recipes, \
game_scene[GAME].player->ingredients[ord]) == 0)
		return (0);
	else
		return (1);
}

int check_others_order_nbr(int value, int ord, scene_t *scene)
{
	switch (value) {
	case sfKeyF4:
		scene[GAME].objs[2]->rect.left = 1050;
		return (3);
	case sfKeyF5:
		scene[GAME].objs[2]->rect.left = 1400;
		return (4);
	default:
		return (ord);
	}
}

int check_order_nbr(sfEvent *event, int ord, scene_t *scene)
{
	int value = 0;

	if (event->type == sfEvtKeyPressed) {
		value = event->key.code;
		switch (value) {
		case sfKeyF1:
			scene[GAME].objs[2]->rect.left = 0;
			return (0);
		case sfKeyF2:
			scene[GAME].objs[2]->rect.left = 350;
			return (1);
		case sfKeyF3:
			scene[GAME].objs[2]->rect.left = 700;
			return (2);
		default:
			return (check_others_order_nbr(value, ord, scene));
		}
	}
	return (ord);
}
