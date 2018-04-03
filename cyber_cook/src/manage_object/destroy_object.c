/*
** EPITECH PROJECT, 2017
** destroy_object
** File description:
** destroy_object
*/

#include "proto.h"

void destroy_object(game_object_t *obj)
{
	if (obj == NULL)
		return;
	sfSprite_destroy(obj->sprite);
	sfTexture_destroy(obj->texture);
	free(obj);
}
