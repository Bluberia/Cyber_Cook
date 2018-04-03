/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene game
*/

#include "proto.h"

int fill_orders_struct(scene_t *game_scene, int nbr, char *order)
{
	int i = 0;

	game_scene->orders[nbr] = malloc(sizeof(orders_t));
	game_scene->orders[nbr]->check = malloc(sizeof(game_object_t *) * 7);
	if (game_scene->orders[nbr] == NULL || \
game_scene->orders[nbr]->check == NULL)
		return (error);
	game_scene->orders[nbr]->recipes = malloc(sizeof(char) * \
(my_strlen(order) + 1));
	if (game_scene->orders[nbr]->recipes == NULL)
		return (error);
	for (; i < my_strlen(order); i++)
		game_scene->orders[nbr]->recipes[i] = order[i];
	game_scene->orders[nbr]->recipes[i] = '\0';
	game_scene->orders[nbr]->time = 60;
	game_scene->orders[nbr]->money = 20;
	create_check_objs(game_scene, nbr);
	for (i = 0; i < 7; i++)
		if (game_scene->orders[nbr]->check[i] == NULL)
			return (error);
	return (0);
}

int init_orders(scene_t *game_scene)
{
	game_scene->orders = malloc(sizeof(orders_t *) * 6);
	if (game_scene->orders == NULL)
		return (error);
	if (fill_orders_struct(game_scene, 0, "UREZ") == error || \
fill_orders_struct(game_scene, 1, "URZA") == error || \
fill_orders_struct(game_scene, 2, "YAZR") == error || \
fill_orders_struct(game_scene, 3, "YERA") == error || \
fill_orders_struct(game_scene, 4, "TRAZ") == error)
		return (error);
	game_scene->orders[5] = NULL;
	for (int i = 0; i < 5; i++)
		game_scene->orders[i]->done = 0;
	return (0);
}

int prepare_game(scene_t *game_scene)
{
	if (game_scene == NULL)
		return (error);
	game_scene->customers = malloc(sizeof(game_object_t *) * 5);
	game_scene->nb_objects = 3;
	game_scene->objs = malloc(sizeof(game_object_t *) * \
game_scene->nb_objects);
	game_scene->nb_buttons = 0;
	game_scene->buttons = NULL;
	game_scene->nb_text = 0;
	game_scene->text = NULL;
	game_scene->type = GAME;
	if (game_scene->objs == NULL || game_scene->customers == NULL)
		return (error);
	if (manage_objects_game(game_scene) == error || \
manage_customers(game_scene) == error || \
init_orders(game_scene) == error || \
init_player_struct(game_scene) == error)
		return (error);
	return (0);
}
