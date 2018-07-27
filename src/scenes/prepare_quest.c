/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** prepare quest text and object
*/

#include "proto.h"

void create_pnj_texts(scene_t *scene)
{
	sfText_setString(scene->text[0]->text, "Bring me back the scroll \n\
of truth.\nI will reward you.");
	sfText_setOrigin(scene->text[0]->text, (sfVector2f){10, 0});
	sfText_setString(scene->text[7]->text, "You found a strange weapon\n\
You look much stronger\nand won +5 attack points\n");
	sfText_setOrigin(scene->text[7]->text, (sfVector2f){10, 0});
	sfText_setString(scene->text[8]->text, "Here, take this armor.\nYou \
should take a look at \nthese stumps, I've seen \nsomething behind...");
	sfText_setOrigin(scene->text[8]->text, (sfVector2f){10, 0});
	sfText_setString(scene->text[9]->text, "I have seen a potato\njust \
like you,\nhe was running in\nin the garden direction.");
	sfText_setOrigin(scene->text[9]->text, (sfVector2f){10, 0});
	sfText_setString(scene->text[10]->text, "Your brother came here but\n \
he went beyond the fence\nand I haven't seen him since...");
	sfText_setOrigin(scene->text[10]->text, (sfVector2f){10, 0});
	sfText_setString(scene->text[11]->text, "Your journey starts here.\n\
Talk to NPC to get information\nabout your brother.");
	sfText_setOrigin(scene->text[11]->text, (sfVector2f){10, 0});
	scene->text[11]->disp = 1;
}

int create_quest_text(scene_t *scene)
{
	sfVector2f position = {60, 70};

	for (int i = 0; i < scene->nb_text; i++) {
		scene->text[i] = malloc(sizeof(text_t));
		if (scene->text[i] == NULL)
			return (ERROR);
		scene->text[i]->font = sfFont_createFromFile("ressource/\
caviar.ttf");
		if (check_create_text(i, scene))
			return (ERROR);
		sfText_setFont(scene->text[i]->text,      \
scene->text[i]->font);
		sfText_setCharacterSize(scene->text[i]->text, 22);
		sfText_setPosition(scene->text[i]->text, position);
		sfText_setColor(scene->text[i]->text, sfWhite);
		scene->text[i]->disp = 0;
	}
	create_pnj_texts(scene);
	return (0);
}

int alloc_quest(scene_t *scene)
{
	for (int i = 0; i < scene->nb_quest; i++) {
		scene->quest[i] = malloc(sizeof(quest_t));
		if (scene->quest[i] == NULL)
			return (ERROR);
		scene->quest[i]->xp = 150;
		scene->quest[i]->done = 0;
		scene->quest[i]->ongoing = 0;
		scene->quest[i]->level_required = 0;
		scene->quest[i]->items_required = 0;
	}
	return (0);
}

void create_quest_objects(scene_t *scenes)
{
	scenes->objs[6] = create_object("ressource/up_stat.png", \
(sfVector2f){500, 10}, (sfIntRect){0, 0, 400, 211}, 0);
	scenes->objs[7] = create_object("ressource/error_skill_point.png", \
(sfVector2f){-5, 500}, (sfIntRect){0, 0, 400, 211}, 0);
	scenes->objs[8] = create_object("ressource/weapons.png", \
(sfVector2f){1373, 233}, (sfIntRect){0, 0, 34, 37}, 0);
	scenes->objs[9] = create_object("ressource/Top_armor.png", \
(sfVector2f){1433, 213}, (sfIntRect){0, 0, 32, 35}, 0);
}