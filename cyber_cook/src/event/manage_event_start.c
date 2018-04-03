/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event start
*/

#include "proto.h"

void manage_event_start_bis(sfRenderWindow* window, sfVector2f click, \
scene_t *game_scene, type_scene_t *scene_actual)
{
	if (buttonisclicked(game_scene[START].buttons[2], click) == 1)
		game_scene[START].buttons[0]->callback(scene_actual, CREDITS);
	if (buttonisclicked(game_scene[START].buttons[3], click) == 1)
		game_scene[START].buttons[0]->callback(scene_actual, EXPLAIN);
	if (buttonisclicked(game_scene[START].buttons[4], click) == 1)
		sfRenderWindow_close(window);
}

void manage_event_start(sfRenderWindow* window, sfEvent *event, \
scene_t *game_scene, type_scene_t *scene_actual)
{
	sfVector2f click;

	if (event->type == sfEvtMouseButtonReleased) {
		click.x = event->mouseButton.x;
		click.y = event->mouseButton.y;
		if (buttonisclicked(game_scene[START].buttons[0], click) == 1)
			game_scene[START].buttons[0]->\
callback(scene_actual, GAME);
		if (buttonisclicked(game_scene[START].buttons[1], click) == 1)
			game_scene[START].buttons[0]->callback(scene_actual, \
PARAMETERS);
		manage_event_start_bis(window, click, game_scene, scene_actual);
	}
}
