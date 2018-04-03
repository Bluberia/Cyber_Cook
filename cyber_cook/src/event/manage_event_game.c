/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event game
*/

#include "proto.h"

void reset_ingredients(scene_t *game_scene, int ord)
{
	for (int i = 0; i < 4; i++)
		game_scene[GAME].player->ingredients[ord][i] = 'X';
}

void check_orders(scene_t *game_scene, int ord)
{
	if (check_if_right_ing(game_scene, ord) == 0)
		game_scene[GAME].player->money += \
game_scene[GAME].orders[ord]->money;
	else
		game_scene[GAME].player->money -= \
game_scene[GAME].orders[ord]->money;
}

void manage_event_game(sfEvent *event, scene_t *game_scene, \
type_scene_t *scene_actual)
{
	static int ord = 0;
	static int ing = 0;

	ord = check_order_nbr(event, ord, game_scene);
	game_scene->save_ord = ord;
	if (event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyEscape)
			*scene_actual = PAUSE;
		if (event->key.code == sfKeySpace && ing == 4) {
			check_orders(game_scene, ord);
			ing = 0;
			reset_ingredients(game_scene, ord);
			game_scene[GAME].orders[ord]->done = 1;
			return;
		}
	}
	if (ing < 4)
		choose_ingredients(event, game_scene, ord, &ing);
}
