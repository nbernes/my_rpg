/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** analyse event
*/

#include "proto.h"

void check_on_events(scene_t *scene)
{
	if (scene[GAME].stage != GARDEN) {
		scene[GAME].objs[4]->disp = 0;
		scene[GAME].text[0]->disp = 0;
		scene[GAME].text[8]->disp = 0;
	}
	if (scene[GAME].stage != FRONTYARD) {
		scene[GAME].text[10]->disp = 0;
	}
	if (scene[GAME].stage == GARDEN && scene[GAME].quest[0]->items_\
required == 0 && scene[GAME].quest[0]->ongoing == 1)
		scene[GAME].objs[4]->disp = 1;
}

void analyse_other_event_scene(sfEvent *event, scene_t *scenes, \
type_scene_t *actual, sfRenderWindow* window)
{
	if (*actual == PARAMETERS)
		event_parameters(window, event, scenes, actual);
	if (*actual == CREDITS)
		event_credits(window, event, scenes, actual);
	if (*actual == EXPLAIN)
		event_explain(window, event, scenes, actual);
	if (*actual == WIN)
		event_win(window, event, scenes, actual);
	if (*actual == LOSE)
		event_lose(window, event, scenes, actual);
}

void analyse_event_scene(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	if (*actual == START)
		event_start(window, event, scenes, actual);
	if (*actual == GAME)
		event_game(event, actual, scenes);
	if (*actual == PAUSE)
		event_pause(window, event, scenes, actual);
	analyse_other_event_scene(event, scenes, actual, window);
}

void actualise_player_stat(scene_t *scene)
{
	char *atk = int_to_string(scene[GAME].actor->atk);
	char *def = int_to_string(scene[GAME].actor->def);
	char *hp = int_to_string(scene[GAME].actor->hp);
	char *level = int_to_string(scene[GAME].actor->level);
	char *xp = int_to_string(scene[GAME].actor->xp);
	char *skill_point = int_to_string(scene[GAME].actor->skill_point);

	sfText_setString(scene[GAME].text[3]->text, atk);
	sfText_setString(scene[GAME].text[4]->text, def);
	sfText_setString(scene[GAME].text[2]->text, hp);
	sfText_setString(scene[GAME].text[1]->text, level);
	sfText_setString(scene[GAME].text[5]->text, xp);
	sfText_setString(scene[GAME].text[6]->text, skill_point);
	if (scene[GAME].actor->xp >= 100) {
		scene[GAME].actor->xp -= 100;
		scene[GAME].actor->level += 1;
		scene[GAME].actor->skill_point += 2;
	}
	free_stats(atk, def, hp, level);
	free_stats_others(xp, skill_point);
}

int analyse_event(sfRenderWindow* window, sfEvent *event, \
scene_t *scenes, type_scene_t *actual)
{
	sfTime time = sfClock_getElapsedTime(scenes->game);
	float seconds = sfTime_asSeconds(time);

	if (seconds > 0.005) {
		sfRenderWindow_clear(window, sfTransparent);
		sfClock_restart(scenes->game);
		if (display(scenes, window, *actual) == ERROR)
			return (ERROR);
		actualise_player_stat(scenes);
		check_on_events(scenes);
	}
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		analyse_event_scene(window, event, scenes, actual);
	}
	return (OK);
}
