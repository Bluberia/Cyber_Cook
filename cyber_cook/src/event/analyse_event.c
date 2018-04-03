/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** analyse event
*/

#include "proto.h"

void analyse_other_event_scene(sfEvent *event, scene_t *game_scene, \
type_scene_t *scene_act, sfRenderWindow* window)
{
	if (*scene_act == PARAMETERS)
		manage_event_parameters(event, game_scene, scene_act);
	if (*scene_act == CREDITS)
		manage_event_credits(event, game_scene, scene_act);
	if (*scene_act == EXPLAIN)
		manage_event_explain(event, game_scene, scene_act);
	if (*scene_act == WIN)
		manage_event_win(window, event, game_scene, scene_act);
	if (*scene_act == LOSE)
		manage_event_lose(window, event, game_scene, scene_act);
}

void analyse_event_scene(sfRenderWindow* window, sfEvent *event, \
scene_t *game_scene, type_scene_t *scene_act)
{
	if (*scene_act == START)
		manage_event_start(window, event, game_scene, scene_act);
	if (*scene_act == GAME)
		manage_event_game(event, game_scene, scene_act);
	if (*scene_act == PAUSE)
		manage_event_pause(window, event, game_scene, scene_act);
	analyse_other_event_scene(event, game_scene, scene_act, window);
}

void analyse_event(sfRenderWindow* window, sfEvent *event, \
scene_t *game_scene, type_scene_t *scene_act)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		analyse_event_scene(window, event, game_scene, scene_act);
	}
	if (*scene_act == GAME)
		display_choose(game_scene, window);
}
