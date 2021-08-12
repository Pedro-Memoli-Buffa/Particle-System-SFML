#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
using namespace std;
using namespace sf;

class Slider {
private:
	Vector2f sliderRange;
	string name;
	Font font;
	Vector2f position;
	Vector2f sliderPosition;
	Vector2f sliderDimensions;
	double sliderValue;


public:
	double getValue();
	void setSlider(Vector2f mousePos);
	void draw(RenderWindow&);

	Slider(Vector2f topLeftPosition, string name, Vector2f valRange, Font font, double initialValue = -1);
};
