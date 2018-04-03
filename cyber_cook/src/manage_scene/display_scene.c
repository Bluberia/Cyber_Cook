/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** display_scene
*/

#include "proto.h"

int manage_sprite_game(scene_t scene, sfRenderWindow* window, sfClock *clock)
{
	int result_time = 0;
	int result_money = 0;

	if (scene.type == GAME) {
		for (int i = 0; i < 5; i++)
			sfSprite_setPosition(scene.customers[i]->sprite, \
scene.customers[i]->position);
		result_money = manage_money(scene, window);
		result_time = manage_timer(scene, window, clock);
		if (result_time == error || result_money == error)
			return (error);
		if (result_time == 1)
			return (1);
		if (result_money == 2)
			return (2);
	}
	return (0);
}

void manage_objs(scene_t scene, int i, sfRenderWindow* window)
{
	sfSprite_setPosition(scene.objs[i]->sprite, scene.objs[i]->position);
	if (scene.type == GAME && i == 2)
		sfSprite_setTextureRect(scene.objs[i]->sprite, \
scene.objs[i]->rect);
	sfRenderWindow_drawSprite(window, scene.objs[i]->sprite, NULL);
}

int display_scene(scene_t scene, sfRenderWindow* window, sfClock *clock)
{
	int result = 0;

	for (int i = 0; i < scene.nb_objects; i++)
		manage_objs(scene, i, window);
	for (int i = 0; i < scene.nb_buttons; i++)
		sfRenderWindow_drawRectangleShape(window, \
scene.buttons[i]->rect, NULL);
	for (int i = 0; i < scene.nb_text; i++)
		sfRenderWindow_drawText(window, scene.text[i]->text, NULL);
	result = manage_sprite_game(scene, window, clock);
	switch (result) {
	case 84:
		return (error);
	case 1:
		return (1);
	case 2:
		return (2);
	default:
		return (0);
	}
}
