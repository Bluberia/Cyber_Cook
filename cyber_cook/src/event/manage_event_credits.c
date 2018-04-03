/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event credits
*/

#include "proto.h"

void manage_event_credits(sfEvent *event, scene_t *game_scene, \
type_scene_t *scene_actual)
{
	if (event->type == sfEvtMouseButtonReleased) {
		if (buttonisclicked(game_scene[CREDITS].buttons[0], \
(sfVector2f){event->mouseButton.x, event->mouseButton.y}) == 1)
			game_scene[CREDITS].buttons[0]->callback\
(scene_actual, START);
	}
	if (event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyEscape)
			*scene_actual = START;
}
