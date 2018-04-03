/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** main
*/

#include "proto.h"

int main(int ac, char **av, char **env)
{
	sfRenderWindow* window;
	scene_t *game_scene;
	sfClock *clock;

	av = av;
	if (ac != 1 || check_env(env) == error)
		return (error);
	window = create_window();
	game_scene = malloc(sizeof(scene_t) * 8);
	clock = sfClock_create();
	if (check_create(&window, &game_scene, clock) == error)
		return (error);
	if (prepare_scenes(game_scene) == error)
		return (error);
	if (launch_game(window, game_scene, clock) == error)
		return (error);
	return (0);
}
