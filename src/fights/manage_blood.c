/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** fight
*/

#include <time.h>
#include <stdio.h>
#include "fight.h"
#include "proto.h"

void prepare_particles(particles_t *particle, int i, float x, float y)
{
	particle[i].color.r = 255;
	particle[i].color.g = 255;
	particle[i].color.b = 255;
	particle[i].color.a = particle[i].life * 5;
	particle[i].position.x = myrand(x, x + 50);
	particle[i].position.y = myrand(y, y + 10);
	particle[i].speed.x = myrand(-1000, 1000);
	particle[i].speed.y = myrand(-1000, 1000);
}

particles_t *init_particles(char *path, float x, float y)
{
	particles_t *particle = malloc(sizeof(particles_t) * MAX_PART_BLOOD);

	if (particle == NULL)
		return (NULL);
	for (int i = 0; i < MAX_PART_BLOOD; i++) {
		particle[i].active = true;
		particle[i].life = 50;
		particle[i].fade = myrand(0.01, 0.05);
		prepare_particles(particle, i, x, y);
		particle[i].texture = sfTexture_createFromFile(path, NULL);
		particle[i].sprite = sfSprite_create();
		if (particle[i].texture == NULL || particle[i].sprite == NULL)
			return (NULL);
		sfSprite_setTexture(particle[i].sprite, particle[i].texture, \
sfTrue);
	}
	return (particle);
}

void restart_particles(particles_t *particle, float x, float y)
{
	for (int i = 0; i < MAX_PART_BLOOD; i++) {
		particle[i].active = true;
		particle[i].life = 50;
		particle[i].fade = myrand(0.01, 0.05);
		prepare_particles(particle, i, x, y);
	}
}

void reinit_particle(particles_t *particle, int i)
{
	if (particle[i].life < 0.0)
		particle[i].active = false;
}

void draw_particles(sfRenderWindow* window, particles_t *particles)
{
	for (int i = 0; i < MAX_PART_BLOOD; i++) {
		if (particles[i].active) {
			sfSprite_setPosition(particles[i].sprite, \
particles[i].position);
			sfSprite_setColor(particles[i].sprite, \
particles[i].color);
			sfRenderWindow_drawSprite(window, \
particles[i].sprite, NULL);
			particles[i].position.x += particles[i].speed.x / 1000;
			particles[i].position.y += particles[i].speed.y / 1000;
			particles[i].life -= particles[i].fade;
			particles[i].color.a = particles[i].life * 5;
			reinit_particle(particles, i);
		}
	}
}
