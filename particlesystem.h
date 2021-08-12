#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "particle.h"
using namespace std;
using namespace sf;

Color rgb(double ratio);

class ParticleSystem {
private:
	vector<Particle> particles;
	Color color;
	double radius;
	double maxLifetime;
	double speed;
	int framesRan;
	bool radiusVariation;
	bool colorVariation;
	double perpDirVariation;
	int emissionPerFrame;
	bool lifeVariation;
	bool transparency;
	double angle;
	vector<Color> rainbowArray;

public:
	void Emit(Vector2f position);
	void ManageLifeTime();
	vector<Particle> GetParticles();
	void SetColor(Color);
	void SetSpeed(double speed);
	void SetMaxLifetime(double lifetime);
	void SetRadiusVariation(bool);
	void SetColorVariation(bool);
	void SetPerpDirVariation(double);
	void SetLifetimeVariation(bool);
	void SetEmission(double);
	void SetRadius(double);
	void SetTransparency(bool);
	void SetAngle(double);

	ParticleSystem();
};

