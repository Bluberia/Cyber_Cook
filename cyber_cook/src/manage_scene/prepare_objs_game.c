/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare objs game
*/

#include "proto.h"

void create_other_check(sfVector2f pos, sfIntRect rect, scene_t *game_scene, \
int nbr)
{
	pos.x += 115;
	pos.y = 110;
	game_scene->orders[nbr]->check[4] = create_object("ressource/\
check.png", pos, rect);
	pos.y += check_diff;
	game_scene->orders[nbr]->check[5] = create_object("ressource/\
check.png", pos, rect);
	pos.y += check_diff;
	game_scene->orders[nbr]->check[6] = create_object("ressource/\
check.png", pos, rect);
}

void create_check_objs(scene_t *game_scene, int nbr)
{
	sfVector2f pos = {1383, 110};
	sfIntRect rect = {0, 0, 0, 0};

	game_scene->orders[nbr]->check[0] = create_object("ressource/\
check.png", pos, rect);
	pos.y += check_diff;
	game_scene->orders[nbr]->check[1] = create_object("ressource/\
check.png", pos, rect);
	pos.y += check_diff;
	game_scene->orders[nbr]->check[2] = create_object("ressource/\
check.png", pos, rect);
	pos.y += check_diff;
	game_scene->orders[nbr]->check[3] = create_object("ressource/\
check.png", pos, rect);
	create_other_check(pos, rect, game_scene, nbr);
}

int manage_objects_game(scene_t *game_scene)
{
	sfIntRect rect = {0, 0, 0, 0};
	sfVector2f pos_recipes = {1250, 20};
	sfIntRect rect_recipes = {0, 0, 350, 69};

	game_scene->objs[0] = create_object("ressource/game_scene.png", \
(sfVector2f){0, 0}, rect);
	game_scene->objs[1] = create_object("ressource/recipes_hud.png", \
(sfVector2f){1275, 31}, rect);
	game_scene->objs[2] = create_object("ressource/recipes.png", \
pos_recipes, rect_recipes);
	for (int i = 0; i < game_scene->nb_objects; i++)
		if (game_scene->objs[i] == NULL)
			return (error);
	return (0);
}

int manage_customers(scene_t *game_scene)
{
	sfIntRect rect = {0, 0, 0, 0};
	sfVector2f pos = {1650, 280};

	game_scene->customers[0] = create_object("ressource/customer_01.png", \
pos, rect);
	game_scene->customers[1] = create_object("ressource/customer_02.png", \
pos, rect);
	game_scene->customers[2] = create_object("ressource/customer_03.png", \
pos, rect);
	game_scene->customers[3] = create_object("ressource/customer_04.png", \
pos, rect);
	game_scene->customers[4] = create_object("ressource/customer_05.png", \
pos, rect);
	for (int i = 0; i < 5; i++)
		if (game_scene->customers == NULL)
			return (error);
	return (0);
}
