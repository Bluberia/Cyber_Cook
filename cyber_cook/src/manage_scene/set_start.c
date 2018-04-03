/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** set start
*/

#include "proto.h"

void set_string_start(scene_t *start_scene)
{
	sfText_setString(start_scene->text[0]->text, "PLAY");
	sfText_setString(start_scene->text[1]->text, "PARAMETERS");
	sfText_setString(start_scene->text[2]->text, "CREDITS");
	sfText_setString(start_scene->text[3]->text, "HOW TO PLAY");
	sfText_setString(start_scene->text[4]->text, "QUIT");
}

void set_origin_start(scene_t *start_scene)
{
	sfFloatRect first = sfText_getGlobalBounds(start_scene->text[0]->text);
	sfVector2f pos_first = {first.width/2, \
start_scene->text[0]->pos_text.y};
	sfFloatRect second = sfText_getGlobalBounds(start_scene->text[1]->text);
	sfVector2f pos_second = {second.width/2, \
start_scene->text[1]->pos_text.y};
	sfFloatRect third = sfText_getGlobalBounds(start_scene->text[2]->text);
	sfVector2f pos_third = {third.width/2, \
start_scene->text[2]->pos_text.y};
	sfFloatRect fourth = sfText_getGlobalBounds(start_scene->text[3]->text);
	sfVector2f pos_fourth = {fourth.width/2, \
start_scene->text[3]->pos_text.y};
	sfFloatRect fifth = sfText_getGlobalBounds(start_scene->text[4]->text);
	sfVector2f pos_fifth = {fifth.width/2, \
start_scene->text[4]->pos_text.y};

	sfText_setOrigin(start_scene->text[0]->text, pos_first);
	sfText_setOrigin(start_scene->text[1]->text, pos_second);
	sfText_setOrigin(start_scene->text[2]->text, pos_third);
	sfText_setOrigin(start_scene->text[3]->text, pos_fourth);
	sfText_setOrigin(start_scene->text[4]->text, pos_fifth);
}
