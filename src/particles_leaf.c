/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** launch game
*/

#include <time.h>
#include <stdbool.h>
#include "proto.h"

void reinit_particle_leaf(particles_t *particle, int i)
{
	if (particle[i].life < 0.0 || particle[i].position.y > 400) {
		particle[i].life = 50;
		particle[i].fade = myrand(0.01, 0.05);
		particle[i].position.x = myrand(750, 900);
		particle[i].position.y = myrand(300, 310);
		particle[i].speed.x = myrand(-1, 1);
		particle[i].speed.y = myrand(0, 500);
		particle[i].color.r = 255;
		particle[i].color.g = 255;
		particle[i].color.b = 255;
		particle[i].color.a = particle[i].life * 5;
	}
}

void prepare_particles_leaf(particles_t *particle, int i)
{
	particle[i].color.r = 255;
	particle[i].color.g = 255;
	particle[i].color.b = 255;
	particle[i].color.a = particle[i].life * 5;
	particle[i].position.x = myrand(750, 900);
	particle[i].position.y = myrand(300, 310);
	particle[i].speed.x = myrand(-1, 1);
	particle[i].speed.y = myrand(0, 500);
}

particles_t *init_particles_leaf(char *path)
{
	particles_t *particle = malloc(sizeof(particles_t) * MAX_PART_LEAF);

	if (particle == NULL)
		return (NULL);
	for (int i = 0; i < MAX_PART_LEAF; i++) {
		particle[i].active = true;
		particle[i].life = 50;
		particle[i].fade = myrand(0.01, 0.05);
		prepare_particles_leaf(particle, i);
		particle[i].texture = sfTexture_createFromFile(path, NULL);
		particle[i].sprite = sfSprite_create();
		if (particle[i].texture == NULL || particle[i].sprite == NULL)
			return (NULL);
		sfSprite_setTexture(particle[i].sprite, particle[i].texture, \
sfTrue);
	}
	return (particle);
}

void draw_particles_leaf(sfRenderWindow* window, particles_t *particles)
{
	for (int i = 0; i < MAX_PART_LEAF; i++) {
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
			reinit_particle_leaf(particles, i);
		}
	}
}
