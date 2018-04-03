/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene win
*/

#include "proto.h"

int manage_objects_win(scene_t *win_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	win_scene->objs[0] = create_object("ressource/Victory.png", \
pos, rect);
	if (win_scene->objs[0] == NULL)
		return (error);
	return (0);
}

int manage_buttons_win(scene_t *win_scene)
{
	int x = 260;
	sfVector2f size = {200, 80};
	sfVector2f position = {x, (window_height / 2) - 5};

	for (int i = 0; i < win_scene->nb_buttons; i++) {
		win_scene->buttons[i] = malloc(sizeof(button_t));
		if (win_scene->buttons[i] == NULL)
			return (error);
		win_scene->buttons[i]->size = size;
		win_scene->buttons[i]->position = position;
		x += 900;
		position.x = x;
		if (buttoninitialise(win_scene->buttons[i]) == error)
			return (error);
	}
	return (0);
}

int manage_text_win(scene_t *win_scene)
{
	int x = 350;
	sfVector2f position = {x, (window_height / 2)};

	for (int i = 0; i < win_scene->nb_text; i++) {
		win_scene->text[i] = malloc(sizeof(text_t));
		win_scene->text[i]->font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
		if (check_create_text(i, win_scene))
			return (error);
		sfText_setFont(win_scene->text[i]->text,	\
win_scene->text[i]->font);
		sfText_setCharacterSize(win_scene->text[i]->text, 50);
		sfText_setPosition(win_scene->text[i]->text, position);
		sfText_setColor(win_scene->text[i]->text, sfWhite);
		x += 900;
		position.x = x;
	}
	set_string_win(win_scene);
	set_origin_win(win_scene);
	return (0);
}

int prepare_win(scene_t *win_scene)
{
	if (win_scene == NULL)
		return (error);
	win_scene->nb_objects = 1;
	win_scene->objs = malloc(sizeof(game_object_t *) * \
win_scene->nb_objects);
	win_scene->nb_buttons = 2;
	win_scene->buttons = malloc(sizeof(button_t *) * \
win_scene->nb_buttons);
	win_scene->nb_text = 2;
	win_scene->text = malloc(sizeof(text_t *) * \
win_scene->nb_text);
	win_scene->type = WIN;
	if (check_malloc_scene(win_scene) == error)
		return (error);
	if (manage_objects_win(win_scene) == error || \
manage_buttons_win(win_scene) == error || \
manage_text_win(win_scene) == error)
		return (error);
	return (0);
}
