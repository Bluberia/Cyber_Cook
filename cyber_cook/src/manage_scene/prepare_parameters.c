/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene parameters
*/

#include "proto.h"

int manage_objects_parameters(scene_t *parameters_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	parameters_scene->objs[0] = create_object("ressource/Menu_params.png", \
pos, rect);
	if (parameters_scene->objs[0] == NULL)
		return (error);
	return (0);
}

int manage_buttons_parameters(scene_t *parameters_scene)
{
	int y = (165 + window_height - (80 * parameters_scene->nb_buttons + \
(offset - 80) * (parameters_scene->nb_buttons - 1))) / 2;

	for (int i = 0; i < parameters_scene->nb_buttons; i++) {
		parameters_scene->buttons[i] = malloc(sizeof(button_t));
		if (parameters_scene->buttons[i] == NULL)
			return (error);
		parameters_scene->buttons[i]->size = (sfVector2f){200, 80};
	}
	parameters_scene->buttons[0]->position = (sfVector2f){600, y};
	parameters_scene->buttons[1]->position = (sfVector2f){30, 30};
	if (buttoninitialise(parameters_scene->buttons[0]) == error ||
buttoninitialise(parameters_scene->buttons[1]) == error)
		return (error);
	return (0);
}

void change_origin_string(scene_t *parameters_scene)
{
	sfFloatRect first;
	sfVector2f pos_first;

	for (int i = 0; i < parameters_scene->nb_text; i++) {
		first = sfText_getGlobalBounds(parameters_scene->text[i]->text);
		pos_first.x = first.width/2;
		pos_first.y = parameters_scene->text[i]->pos_text.y;
		sfText_setOrigin(parameters_scene->text[i]->text, pos_first);
	}
	sfText_setString(parameters_scene->text[0]->text, "ON/OFF");
	sfText_setString(parameters_scene->text[1]->text, "BACK");
}

int manage_text_parameters(scene_t *parameters_scene)
{
	sfVector2f pos = {640, (165 + window_height - (80 * parameters_scene-> \
nb_buttons + (offset - 80) * (parameters_scene->nb_buttons - 1))) / 2 + 20};

	for (int i = 0; i < parameters_scene->nb_text; i++) {
		parameters_scene->text[i] = malloc(sizeof(text_t));
		parameters_scene->text[i]->font = sfFont_createFromFile("\
ressource/Caviar_Dreams_Bold.ttf");
		if (check_create_text(i, parameters_scene))
			return (error);
		sfText_setFont(parameters_scene->text[i]->text, \
parameters_scene->text[i]->font);
		sfText_setCharacterSize(parameters_scene->text[i]->text, 30);
		sfText_setColor(parameters_scene->text[i]->text, sfWhite);
	}
	sfText_setPosition(parameters_scene->text[0]->text, pos);
	sfText_setPosition(parameters_scene->text[1]->text, \
(sfVector2f){90, 50});
	change_origin_string(parameters_scene);
	return (0);
}

int prepare_parameters(scene_t *parameters_scene)
{
	if (parameters_scene == NULL)
		return (error);
	parameters_scene->nb_objects = 1;
	parameters_scene->objs = malloc(sizeof(game_object_t *) * \
parameters_scene->nb_objects);
	parameters_scene->nb_buttons = 2;
	parameters_scene->buttons = malloc(sizeof(button_t *) * \
parameters_scene->nb_buttons);
	parameters_scene->nb_text = 2;
	parameters_scene->text = malloc(sizeof(text_t *) * \
parameters_scene->nb_text);
	parameters_scene->type = PARAMETERS;
	if (check_malloc_scene(parameters_scene) == error || \
manage_objects_parameters(parameters_scene) == error || \
manage_buttons_parameters(parameters_scene) == error ||	\
manage_text_parameters(parameters_scene) == error)
		return (error);
	return (0);
}
