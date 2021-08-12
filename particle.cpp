#include "particle.h"

void Particle::ChangeColor(Color newColor) {
	color = newColor;
}

void Particle::Move() {
	double radAngle = angle * 0.01745329252;
	Vector2f direction(cos(radAngle), sin(radAngle));
	Vector2f variationDirection(-direction.y * variation * cos(lifetime * 0.01745329252 * 6), -direction.x * variation * cos(lifetime * 0.01745329252 * 6));
	currentPosition = Vector2f(currentPosition.x + speed * cos(radAngle) + variationDirection.x, currentPosition.y + speed * sin(-radAngle) + variationDirection.y);
	lifetime += 1;
	if (transparency) {
		if (lifetime / maxLifetime > 0.4) color.a = 255 * (maxLifetime - lifetime) / maxLifetime;
	}
}

CircleShape Particle::GetShape() {
	CircleShape particleShape(radius);
	particleShape.setFillColor(color);
	particleShape.setOrigin(Vector2f(radius, radius));
	particleShape.setPosition(currentPosition);
	
	return particleShape;
}

bool Particle::IsAlive() {
	return !(lifetime > maxLifetime);
}

void Particle::SetVariation(double newVariation) {
	variation = newVariation;
}

void Particle::SetTransparency(bool value) {
	transparency = value;
}

Particle::Particle(Vector2f position, Color color, double radius, double maxLifetime, double angle, double speed) {
	this->variation = 0;
	this->centerPoint = position;
	this->currentPosition = centerPoint;
	this->color = color;
	this->radius = radius;
	this->maxLifetime = maxLifetime;
	this->angle = angle;
	this->speed = speed;
	this->lifetime = 0;
	this->transparency = false;
}