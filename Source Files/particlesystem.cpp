#include "particlesystem.h"
#include <stdlib.h>


Color rgb(double ratio)  // Getting rainbow color array
{
	//we want to normalize ratio so that it fits in to 6 regions
	//where each region is 256 units long
	int normalized = int(ratio * 256 * 6);

	//find the distance to the start of the closest region
	int x = normalized % 256;

	int red = 0, grn = 0, blu = 0;
	switch (normalized / 256)
	{
	case 0: red = 255;      grn = x;        blu = 0;       break;//red
	case 1: red = 255 - x;  grn = 255;      blu = 0;       break;//yellow
	case 2: red = 0;        grn = 255;      blu = x;       break;//green
	case 3: red = 0;        grn = 255 - x;  blu = 255;     break;//cyan
	case 4: red = x;        grn = 0;        blu = 255;     break;//blue
	case 5: red = 255;      grn = 0;        blu = 255 - x; break;//magenta
	}

	return Color(red, grn, blu);
}

void ParticleSystem::Emit(Vector2f position, double angle) {
	for (int i = 0; i < emissionPerFrame; i++) {
		double properAngle;
		if (angle == -1) {  // Emits in a circle
			properAngle = rand() % 365;
		}
		else if (angle == -2) {
			properAngle = framesRan * 2 + rand() % 100 - 50;
		}
		else {
			properAngle = angle + rand() % 60 - 30;
		}

		if (colorVariation) {
			color = rainbowArray[framesRan % 500];
		}

		double properRadius;
		if (radiusVariation) {
			properRadius = radius + rand() % 3 - 1;
		}
		else properRadius = radius;

		double properLifeTime;
		if (lifeVariation) {
			properLifeTime = maxLifetime - rand() % 40;
		}
		else properLifeTime = maxLifetime;


		Particle particle(position, color, properRadius, properLifeTime, properAngle, speed);

		particle.SetVariation(perpDirVariation);

		particles.push_back(particle);
	}

	framesRan++;
}

void ParticleSystem::ManageLifeTime() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].Move();

		if (!particles[i].IsAlive()) {
			particles.erase(particles.begin() + i);
		}
	}
}

vector<Particle> ParticleSystem::GetParticles() {
	return particles;
}

void ParticleSystem::SetColor(Color newColor) {
	color = newColor;
}

void ParticleSystem::SetSpeed(double newSpeed) {
	speed = newSpeed;
}

void ParticleSystem::SetMaxLifetime(double lifetime) {
	maxLifetime = lifetime;
}

void ParticleSystem::SetRadiusVariation(bool value) {
	radiusVariation = value;
}

void ParticleSystem::SetColorVariation(bool value) {
	colorVariation = value;
}

void ParticleSystem::SetPerpDirVariation(double newVariation) {
	perpDirVariation = newVariation;
}

void ParticleSystem::SetLifetimeVariation(bool value) {
	lifeVariation = value;
}


ParticleSystem::ParticleSystem() {
	this->framesRan = 0;
	this->color = Color::White;
	this->radius = 3;
	this->maxLifetime = 90;
	this->speed = 2;
	this->framesRan = 0;
	this->radiusVariation = false;
	this->colorVariation = false;
	this->perpDirVariation = 0;
	this->emissionPerFrame = 2;
	this->lifeVariation = false;

	double range = 500;
	for (int i = 0; i < range; i++) {
		Color color = rgb(i / range);
		rainbowArray.push_back(color);
	}
}