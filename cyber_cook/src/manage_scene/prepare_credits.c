/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** prepare scene credits
*/

#include "proto.h"

int manage_objects_credits(scene_t *credits_scene)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 0, 0};

	credits_scene->objs[0] = create_object("ressource/Menu_credits.png", \
pos, rect);
	if (credits_scene->objs[0] == NULL)
		return (error);
	return (0);
}

int manage_buttons_credits(scene_t *credits_scene)
{
	sfVector2f size = {200, 80};
	sfVector2f position = {30, 30};

	credits_scene->buttons[0] = malloc(sizeof(button_t));
	if (credits_scene->buttons[0] == NULL)
		return (error);
	credits_scene->buttons[0]->size = size;
	credits_scene->buttons[0]->position = position;
	if (buttoninitialise(credits_scene->buttons[0]) == error)
		return (error);
	return (0);
}

int manage_text_credits(scene_t *credits_scene)
{
	sfFloatRect first;
	sfVector2f pos_first;
	sfVector2f position = {90, 50};

	credits_scene->text[0] = malloc(sizeof(text_t));
	credits_scene->text[0]->font = sfFont_createFromFile("ressource/\
Caviar_Dreams_Bold.ttf");
	if (check_create_text(0, credits_scene))
		return (error);
	sfText_setFont(credits_scene->text[0]->text, \
credits_scene->text[0]->font);
	sfText_setCharacterSize(credits_scene->text[0]->text, 30);
	sfText_setPosition(credits_scene->text[0]->text, position);
	sfText_setColor(credits_scene->text[0]->text, sfWhite);
	first = sfText_getGlobalBounds(credits_scene->text[0]->text);
	pos_first.x = first.width/2;
	pos_first.y = credits_scene->text[0]->pos_text.y;
	sfText_setString(credits_scene->text[0]->text, "BACK");
	sfText_setOrigin(credits_scene->text[0]->text, pos_first);
	return (0);
}

int prepare_credits(scene_t *credits_scene)
{
	if (credits_scene == NULL)
		return (error);
	credits_scene->nb_objects = 1;
	credits_scene->objs = malloc(sizeof(game_object_t *) * \
credits_scene->nb_objects);
	credits_scene->nb_buttons = 1;
	credits_scene->buttons = malloc(sizeof(button_t *) * \
credits_scene->nb_buttons);
	credits_scene->nb_text = 1;
	credits_scene->text = malloc(sizeof(text_t *) * \
credits_scene->nb_text);
	credits_scene->type = CREDITS;
	if (check_malloc_scene(credits_scene) == error)
		return (error);
	if (manage_objects_credits(credits_scene) == error || \
manage_buttons_credits(credits_scene) == error || \
manage_text_credits(credits_scene) == error)
		return (error);
	return (0);
}
