/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage customers event
*/

#include "proto.h"

void set_customers_pos_and_display(sfRenderWindow *window, scene_t *\
game_scene, int nbr)
{
	sfSprite_setPosition(game_scene[GAME].customers[nbr]->sprite, \
game_scene[GAME].customers[nbr]->position);
	sfRenderWindow_drawSprite(window, game_scene[GAME].\
customers[nbr]->sprite, NULL);
}

void move_next_customer(scene_t *game_scene, int client ,int max_pos)
{
	if (client == 4 && game_scene[GAME].customers[client]->position.x \
< 1040)
		return;
	if (game_scene[GAME].customers[client]->position.x > max_pos) {
		game_scene[GAME].customers[client]->position.x -= 10;
		return;
	}
}

int check_if_someone_left(scene_t *game_scene)
{
	for (int i = 0; i < 5; i++) {
		if (game_scene[GAME].orders[i]->done != 0)
			return (i);
	}
	return (-1);
}

int display_and_check_pos(sfRenderWindow *window, scene_t *game_scene, \
int customer)
{
	for (int i = 0; i < 5; i++)
		set_customers_pos_and_display(window, game_scene, i);
	if (game_scene[GAME].customers[customer]->position.x == (260 * \
customer)) {
		customer++;
	}
	for (int j = 0; j < 5; j++) {
		if (game_scene[GAME].customers[j]->position.x != (260 * j))
			return (j);
	}
	if (customer > 4)
		customer -= 1;
	return (customer);
}

void send_customers(sfRenderWindow *window, scene_t *game_scene)
{
	static int customer = 0;
	int left = -1;
	sfTime time = sfClock_getElapsedTime(game_scene[GAME].player->clock);
	float seconds = sfTime_asSeconds(time);

	left = check_if_someone_left(game_scene);
	if (left != -1) {
		game_scene[GAME].customers[left]->position.x = 1600;
		game_scene[GAME].orders[left]->done = 0;
	}
	if (seconds > 0.025) {
		move_next_customer(game_scene, customer, 0);
		sfClock_restart(game_scene[GAME].player->clock);
	}
	customer = display_and_check_pos(window, game_scene, customer);
}
