/*
** EPITECH PROJECT, 2018
** buttonInitialise
** File description:
** Initialisation of the button
*/

#include "proto.h"

int buttoninitialise(button_t *button)
{
	button->rect = sfRectangleShape_create();
	if (button->rect == NULL)
		return (84);
	sfRectangleShape_setPosition(button->rect, button->position);
	sfRectangleShape_setSize(button->rect, button->size);
	sfRectangleShape_setFillColor(button->rect, sfBlack);
	button->callback = &change_value_actual;
	return (0);
}
