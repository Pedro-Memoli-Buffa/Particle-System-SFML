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
}

CircleShape Particle::GetShape() {
	CircleShape particleShape(radius);
	particleShape.setFillColor(color);
	particleShape.setOrigin(Vector2f(radius, radius));
	particleShape.setPosition(currentPosition);
	
	return particleShape;
}

bool Particle::IsAlive() {
	if (lifetime > maxLifetime) return false;
	else return true;
}

void Particle::SetVariation(double newVariation) {
	variation = newVariation;
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
	this->alpha = 255;
	this->lifetime = 0;
}