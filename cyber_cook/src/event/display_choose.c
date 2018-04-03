/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** display ingredients choosen with a check
*/

#include "proto.h"

void display_again_other_choose(sfRenderWindow* window, scene_t *scene, \
int to_find, int ord)
{
	switch (to_find) {
	case 'T':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[4]->sprite, NULL);
		break;
	case 'Y':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[1]->sprite, NULL);
		break;
	case 'U':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[0]->sprite, NULL);
			break;
	default:
		return;
	}
}

void display_other_choose(sfRenderWindow* window, scene_t *scene, \
int to_find, int ord)
{
	switch (to_find) {
	case 'Z':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[5]->sprite, NULL);
		break;
	case 'E':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[3]->sprite, NULL);
		break;
	case 'R':
		sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[6]->sprite, NULL);
		break;
	default:
		display_again_other_choose(window, scene, to_find, ord);
		return;
	}
}

void display_choose(scene_t *scene, sfRenderWindow* window)
{
	int ord = scene->save_ord;
	char to_find;

	for (int i = 0; i < 7; i++)
		sfSprite_setPosition(scene[GAME].orders[ord]->check[i]->\
sprite, scene[GAME].orders[ord]->check[i]->position);
	for (int i = 0; scene[GAME].player->ingredients[ord][i]; i++) {
		to_find = scene[GAME].player->ingredients[ord][i];
		switch (to_find) {
		case 'A':
			sfRenderWindow_drawSprite(window, \
scene[GAME].orders[ord]->check[2]->sprite, NULL);
			break;
		default:
			display_other_choose(window, scene, to_find, ord);
			continue;
		}
	}
}
