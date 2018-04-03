/*
** EPITECH PROJECT, 2017
** game object
** File description:
** game object struct
*/

#include <SFML/Graphics.h>

#ifndef __GAME_OBJECT_H_
#define __GAME_OBJECT_H_

typedef struct s_game_object
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfIntRect rect;
} game_object_t;

game_object_t *create_object(const char *, sfVector2f, sfIntRect);
void destroy_object(game_object_t *);

#endif
