/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** create window
*/

#include "proto.h"

sfRenderWindow* create_window(void)
{
	sfVideoMode mode = {window_width, window_height, 32};
	sfRenderWindow* window = sfRenderWindow_create(mode, "CYBER Cook", \
sfClose, NULL);

	if (window == NULL) {
		my_putstr("Error in Window creation process\n");
		return (NULL);
	}
	sfRenderWindow_setFramerateLimit(window, 50);
	return (window);
}
