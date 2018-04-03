/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene explain
*/

#include "proto.h"

int manage_objects_explain(scene_t *explain_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	explain_scene->objs[0] = create_object("ressource/Menu_explain.png", \
pos, rect);
	if (explain_scene->objs[0] == NULL)
		return (error);
	return (0);
}

int manage_buttons_explain(scene_t *explain_scene)
{
	sfVector2f size = {200, 80};
	sfVector2f position = {30, 30};

	explain_scene->buttons[0] = malloc(sizeof(button_t));
	if (explain_scene->buttons[0] == NULL)
		return (error);
	explain_scene->buttons[0]->size = size;
	explain_scene->buttons[0]->position = position;
	if (buttoninitialise(explain_scene->buttons[0]) == error)
		return (error);
	return (0);
}

int manage_text_explain(scene_t *explain_scene)
{
	sfFloatRect first;
	sfVector2f pos_first;
	sfVector2f position = {90, 50};

	explain_scene->text[0] = malloc(sizeof(text_t));
	explain_scene->text[0]->font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
	if (check_create_text(0, explain_scene))
		return (error);
	sfText_setFont(explain_scene->text[0]->text, \
explain_scene->text[0]->font);
	sfText_setCharacterSize(explain_scene->text[0]->text, 30);
	sfText_setPosition(explain_scene->text[0]->text, position);
	sfText_setColor(explain_scene->text[0]->text, sfWhite);
	first = sfText_getGlobalBounds(explain_scene->text[0]->text);
	pos_first.x = first.width/2;
	pos_first.y = explain_scene->text[0]->pos_text.y;
	sfText_setString(explain_scene->text[0]->text, "BACK");
	sfText_setOrigin(explain_scene->text[0]->text, pos_first);
	return (0);
}

int prepare_explain(scene_t *explain_scene)
{
	if (explain_scene == NULL)
		return (error);
	explain_scene->nb_objects = 1;
	explain_scene->objs = malloc(sizeof(game_object_t *) * \
explain_scene->nb_objects);
	explain_scene->nb_buttons = 1;
	explain_scene->buttons = malloc(sizeof(button_t *) * \
explain_scene->nb_buttons);
	explain_scene->nb_text = 1;
	explain_scene->text = malloc(sizeof(text_t *) * \
explain_scene->nb_text);
	explain_scene->type = EXPLAIN;
	if (check_malloc_scene(explain_scene) == error)
		return (error);
	if (manage_objects_explain(explain_scene) == error || \
manage_buttons_explain(explain_scene) == error || \
manage_text_explain(explain_scene) == error)
		return (error);
	return (0);
}
