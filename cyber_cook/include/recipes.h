/*
** EPITECH PROJECT, 2018
** cook
** File description:
** lib for recipes
*/

#include "proto.h"

#ifndef __RECIPES_H_
#define __RECIPES_H_

typedef struct s_orders
{
	char *recipes;
	game_object_t **check;
	game_object_t objs;
	int time;
	int money;
	int done;
} orders_t;

#endif
