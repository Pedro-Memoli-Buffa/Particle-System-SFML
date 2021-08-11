#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

class Particle {
private:
	Vector2f centerPoint;
	Vector2f currentPosition;
	Color color;
	double radius;
	double lifetime;  // In seconds
	double maxLifetime;
	double alpha;  // Transparency
	double angle;  // For movement from center point
	double speed;
	double variation;

public:
	void SetVariation(double);
	void ChangeColor(Color);
	void Move();
	CircleShape GetShape();
	bool IsAlive();

	Particle(Vector2f position, Color, double, double, double, double);
};

