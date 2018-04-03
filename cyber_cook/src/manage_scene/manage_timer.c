/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** display_scene
*/

#include "proto.h"

int prepare_text(scene_t scene, sfRenderWindow* window)
{
	sfFont* font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
	sfText* text = sfText_create();
	sfVector2f pos_text = {225, 0};

	if (font == NULL || text == NULL)
		return (error);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setPosition(text, pos_text);
	sfText_setColor(text, sfWhite);
	sfText_setStyle(text, sfTextBold);
	sfText_setString(text, change_time(scene.player->time));
	sfRenderWindow_drawText(window, text, NULL);
	return (0);
}

int manage_timer(scene_t scene, sfRenderWindow* window, sfClock *clock)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 500000;

	if (prepare_text(scene, window) == error)
		return (error);
	if (seconds > 1.0) {
		if (scene.player->time == 0)
			return (1);
		if (scene.player->time == 500 || scene.player->time == 400 || \
scene.player->time == 300 || scene.player->time == 200 || \
scene.player->time == 100)
			scene.player->time -= 41;
		else
			scene.player->time -= 1;
		sfClock_restart(clock);
	}
	return (0);
}
