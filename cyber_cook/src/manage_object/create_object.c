/*
** EPITECH PROJECT, 2017
** create_object
** File description:
** create_object
*/

#include "proto.h"

game_object_t *create_object(const char *path_to_spritesheet, \
sfVector2f pos, sfIntRect rect)
{
	game_object_t *object = malloc(sizeof(*object));

	if (object == NULL)
		return (NULL);
	object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	if (object->texture == NULL)
		return (NULL);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->position = pos;
	object->rect = rect;
	return (object);
}
