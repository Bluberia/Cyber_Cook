/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** set pause
*/

#include "proto.h"

void set_string_pause(scene_t *pause_scene)
{
	sfText_setString(pause_scene->text[0]->text, "CONTINUE");
	sfText_setString(pause_scene->text[1]->text, "MENU");
	sfText_setString(pause_scene->text[2]->text, "QUIT");
}

void set_origin_pause(scene_t *pause_scene)
{
	sfFloatRect first = sfText_getGlobalBounds(pause_scene->text[0]->text);
	sfVector2f pos_first = {first.width/2, \
pause_scene->text[0]->pos_text.y};
	sfFloatRect second = sfText_getGlobalBounds(pause_scene->text[1]->text);
	sfVector2f pos_second = {second.width/2, \
pause_scene->text[1]->pos_text.y};
	sfFloatRect third = sfText_getGlobalBounds(pause_scene->text[2]->text);
	sfVector2f pos_third = {third.width/2, \
pause_scene->text[2]->pos_text.y};

	sfText_setOrigin(pause_scene->text[0]->text, pos_first);
	sfText_setOrigin(pause_scene->text[1]->text, pos_second);
	sfText_setOrigin(pause_scene->text[2]->text, pos_third);
}
