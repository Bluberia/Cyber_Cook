/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage event lose
*/

#include "proto.h"

void manage_event_lose(sfRenderWindow* window, sfEvent *event, \
scene_t *game_scene, type_scene_t *scene_actual)
{
	sfVector2f click;

	if (event->type == sfEvtMouseButtonReleased) {
		click.x = event->mouseButton.x;
		click.y = event->mouseButton.y;
		if (buttonisclicked(game_scene[LOSE].buttons[0], click) == 1) {
			game_scene[LOSE].buttons[0]->callback\
(scene_actual, START);
			reset_game(game_scene);
		}
		if (buttonisclicked(game_scene[LOSE].buttons[1], click) == 1)
			sfRenderWindow_close(window);
	}
}
