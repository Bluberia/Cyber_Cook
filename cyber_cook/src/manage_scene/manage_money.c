/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** manage money for the game
*/

#include "proto.h"

int manage_money(scene_t scene, sfRenderWindow* window)
{
	sfFont* font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
	sfText* text = sfText_create();
	sfVector2f pos_text = {60, 0};

	if (font == NULL || text == NULL)
		return (error);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setPosition(text, pos_text);
	sfText_setColor(text, sfWhite);
	sfText_setStyle(text, sfTextBold);
	sfText_setString(text, int_to_string(scene.player->money));
	sfRenderWindow_drawText(window, text, NULL);
	if (scene.player->money <= 0)
		return (2);
	return (0);
}
