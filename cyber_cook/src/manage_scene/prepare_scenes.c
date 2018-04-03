/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scenes
*/

#include "proto.h"

int check_malloc_scene(scene_t *scene)
{
	if (scene->objs == NULL || scene->buttons == NULL || \
scene->text == NULL) {
		if (scene->objs != NULL)
			free(scene->objs);
		if (scene->buttons != NULL)
			free(scene->buttons);
		if (scene->text != NULL)
			free(scene->text);
		return (error);
	}
	return (0);
}

int prepare_music(scene_t *game_scene)
{
	game_scene->music = sfMusic_createFromFile("ressource/music.ogg");
	if (game_scene->music == NULL)
		return (error);
	game_scene->state_music = 1;
	sfMusic_setLoop(game_scene->music, sfTrue);
	sfMusic_play(game_scene->music);
	game_scene->save_ord = 0;
	return (0);
}

int prepare_scenes(scene_t *scene)
{
	if (prepare_start(&scene[0]) == error)
		return (error);
	if (prepare_pause(&scene[1]) == error)
		return (error);
	if (prepare_credits(&scene[2]) == error)
		return (error);
	if (prepare_explain(&scene[3]) == error)
		return (error);
	if (prepare_parameters(&scene[4]) == error)
		return (error);
	if (prepare_game(&scene[5]) == error)
		return (error);
	if (prepare_win(&scene[6]) == error || prepare_lose(&scene[7]) == error)
		return (error);
	return (prepare_music(scene));
}
