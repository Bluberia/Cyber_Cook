/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** launch game
*/

#include "proto.h"

int launch_game(sfRenderWindow* window, scene_t *game_scene, sfClock *clock)
{
	sfEvent event;
	type_scene_t scene_actual = START;
	int result = 0;

	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		result = display_scene(game_scene[scene_actual], window, clock);
		analyse_event(window, &event, game_scene, &scene_actual);
		if (result == error)
			return (error);
		if (result == 1)
			scene_actual = WIN;
		if (result == 2)
			scene_actual = LOSE;
		if (scene_actual == GAME)
			send_customers(window, game_scene);
		sfRenderWindow_display(window);
	}
	sfMusic_destroy(game_scene->music);
	sfRenderWindow_destroy(window);
	return (0);
}
