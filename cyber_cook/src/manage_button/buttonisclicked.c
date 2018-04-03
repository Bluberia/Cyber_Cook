/*
** EPITECH PROJECT, 2018
** button is clicked
** File description:
** button is clicked
*/

#include "proto.h"

int buttonisclicked(button_t *button, sfVector2f clickPosition)
{
	sfVector2f pos = sfRectangleShape_getPosition(button->rect);
	sfVector2f size = sfRectangleShape_getSize(button->rect);

	if (pos.x <= clickPosition.x && clickPosition.x <= (pos.x + size.x))
		if (pos.y <= clickPosition.y && clickPosition.y <= \
(pos.y + size.y))
			return (1);
	return (0);
}
