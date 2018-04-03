/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** check at start of my cook
*/

#include "proto.h"

int check_create(sfRenderWindow** window, scene_t **game_scene, sfClock *clock)
{
	if (*window == NULL || *game_scene == NULL || clock == NULL) {
		if (*game_scene != NULL)
			free(*game_scene);
		if (*window != NULL)
			sfRenderWindow_destroy(*window);
		return (error);
	}
	return (0);
}

char *fill_compare(char **env, int i)
{
	int y = 0;
	char *compare = NULL;

	while (env[i][y] != '=' && env[i][y] != '\0')
		y++;
	compare = malloc(sizeof(char) * (y + 1));
	if (compare == NULL)
		return (NULL);
	y = 0;
	while (env[i][y] != '=' && env[i][y] != '\0') {
		compare[y] = env[i][y];
		y++;
	}
	compare[y] = '\0';
	return (compare);
}

int check_env(char **env)
{
	int i = 0;
	char *compare = NULL;

	while (env[i] != NULL) {
		compare = fill_compare(env, i);
		if (compare == NULL)
			return (error);
		if (my_strcmp(compare, "DISPLAY") == 0) {
			free(compare);
			return (0);
		}
		free(compare);
		i++;
	}
	my_putstr("You don't have DISPLAY in your environment.\n");
	return (error);
}
