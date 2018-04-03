/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** set win
*/

#include "proto.h"

void set_string_win(scene_t *win_scene)
{
	sfText_setString(win_scene->text[0]->text, "MENU");
	sfText_setString(win_scene->text[1]->text, "QUIT");
}

void set_origin_win(scene_t *win_scene)
{
	sfFloatRect first = sfText_getGlobalBounds(win_scene->text[0]->text);
	sfVector2f pos_first = {first.width/2, \
win_scene->text[0]->pos_text.y};
	sfFloatRect second = sfText_getGlobalBounds(win_scene->text[1]->text);
	sfVector2f pos_second = {second.width/2, \
win_scene->text[1]->pos_text.y};

	sfText_setOrigin(win_scene->text[0]->text, pos_first);
	sfText_setOrigin(win_scene->text[1]->text, pos_second);
}
