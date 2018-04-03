/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene start
*/

#include "proto.h"

int manage_objects_start(scene_t *start_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	start_scene->objs[0] = create_object("ressource/Menu_start.png", \
pos, rect);
	if (start_scene->objs[0] == NULL)
		return (error);
	return (0);
}

int manage_buttons_start(scene_t *start_scene)
{
	int y = (165 + window_height - (80 * start_scene->nb_buttons + \
(offset - 80) * (start_scene->nb_buttons - 1))) / 2;
	sfVector2f size = {575, 80};
	sfVector2f position = {505, y};

	for (int i = 0; i < start_scene->nb_buttons; i++) {
		start_scene->buttons[i] = malloc(sizeof(button_t));
		if (start_scene->buttons[i] == NULL)
			return (error);
		start_scene->buttons[i]->size = size;
		start_scene->buttons[i]->position = position;
		y += offset;
		position.y = y;
		if (buttoninitialise(start_scene->buttons[i]) == error)
			return (error);
	}
	return (0);
}

int check_create_text(int i, scene_t *start_scene)
{
	start_scene->text[i]->text = sfText_create();
	if (start_scene->text[i]->font == NULL || \
start_scene->text[i]->text == NULL)
		return (error);
	return (0);
}

int manage_text_start(scene_t *start_scene)
{
	int y = ((165 + window_height - (80 * start_scene->nb_buttons +	\
(offset - 80) * (start_scene->nb_buttons - 1))) / 2) + 5;
	sfVector2f position = {(window_width / 2), y};

	for (int i = 0; i < start_scene->nb_text; i++) {
		start_scene->text[i] = malloc(sizeof(text_t));
		start_scene->text[i]->font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
		if (check_create_text(i, start_scene))
			return (error);
		sfText_setFont(start_scene->text[i]->text,	\
start_scene->text[i]->font);
		sfText_setCharacterSize(start_scene->text[i]->text, 50);
		sfText_setPosition(start_scene->text[i]->text, position);
		sfText_setColor(start_scene->text[i]->text, sfWhite);
		y += offset;
		position.y = y;
	}
	set_string_start(start_scene);
	set_origin_start(start_scene);
	return (0);
}

int prepare_start(scene_t *start_scene)
{
	if (start_scene == NULL)
		return (error);
	start_scene->nb_objects = 1;
	start_scene->objs = malloc(sizeof(game_object_t *) * \
start_scene->nb_objects);
	start_scene->nb_buttons = 5;
	start_scene->buttons = malloc(sizeof(button_t *) * \
start_scene->nb_buttons);
	start_scene->nb_text = 5;
	start_scene->text = malloc(sizeof(text_t *) * \
start_scene->nb_text);
	start_scene->type = START;
	if (check_malloc_scene(start_scene) == error)
		return (error);
	if (manage_objects_start(start_scene) == error || \
manage_buttons_start(start_scene) == error || \
manage_text_start(start_scene) == error)
		return (error);
	return (0);
}
