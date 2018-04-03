/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** set lose
*/

#include "proto.h"

void set_string_lose(scene_t *lose_scene)
{
	sfText_setString(lose_scene->text[0]->text, "MENU");
	sfText_setString(lose_scene->text[1]->text, "QUIT");
}

void set_origin_lose(scene_t *lose_scene)
{
	sfFloatRect first = sfText_getGlobalBounds(lose_scene->text[0]->text);
	sfVector2f pos_first = {first.width/2, \
lose_scene->text[0]->pos_text.y};
	sfFloatRect second = sfText_getGlobalBounds(lose_scene->text[1]->text);
	sfVector2f pos_second = {second.width/2, \
lose_scene->text[1]->pos_text.y};

	sfText_setOrigin(lose_scene->text[0]->text, pos_first);
	sfText_setOrigin(lose_scene->text[1]->text, pos_second);
}
