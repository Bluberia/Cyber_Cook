/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event parameters
*/

#include "proto.h"

void manage_music(scene_t *game_scene)
{
	if (game_scene->state_music == 1) {
		sfMusic_stop(game_scene->music);
		game_scene->state_music = 0;
	} else if (game_scene->state_music == 0) {
		sfMusic_play(game_scene->music);
		game_scene->state_music = 1;
	}
}

void manage_event_parameters(sfEvent *event, scene_t *game_scene, \
type_scene_t *scene_actual)
{
	if (event->type == sfEvtMouseButtonReleased) {
		if (buttonisclicked(game_scene[PARAMETERS].buttons[1], \
(sfVector2f){event->mouseButton.x, event->mouseButton.y}) == 1)
			game_scene[PARAMETERS].buttons[1]->\
callback(scene_actual, START);
		if (buttonisclicked(game_scene[PARAMETERS].buttons[0], \
(sfVector2f){event->mouseButton.x, event->mouseButton.y}) == 1) {
			manage_music(game_scene);
		}
	}
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			*scene_actual = START;
}
