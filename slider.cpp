#include "slider.h"

double Slider::getValue() {
	return sliderValue;
}

void Slider::setSlider(Vector2f mousePos) {
	double spacingTolerance = 12;
	if (sliderPosition.x - 3 < mousePos.x && mousePos.x < sliderPosition.x + sliderDimensions.x + 3
		&& sliderPosition.y - spacingTolerance < mousePos.y && mousePos.y < sliderPosition.y + sliderDimensions.y + spacingTolerance) {
		double ratio = (mousePos.x - sliderPosition.x) / 130;
		sliderValue = sliderRange.x + ((double)sliderRange.y - (double)sliderRange.x) * ratio;
	}
}

void Slider::draw(RenderWindow& window) {
	// Draws text
	Text text;
	text.setFont(font);

	string trimmedValue = to_string(sliderValue).substr(0, std::to_string(sliderValue).find(".") + 1 + 1);

	text.setString(name + ": " + trimmedValue);
	text.setCharacterSize(15);
	text.setFillColor(Color::White);
	text.setPosition(position);

	// Draws slider
	RectangleShape line(sliderDimensions);
	line.setFillColor(Color::White);
	line.setPosition(sliderPosition);
	
	double radius = 5;
	CircleShape valuePoint(radius);
	valuePoint.setFillColor(Color::White);
	valuePoint.setOrigin(Vector2f(radius, radius));
	valuePoint.setPosition(sliderPosition.x + sliderDimensions.x * sliderValue / sliderRange.y, sliderPosition.y + 1.5);
	
	// Drawing to window
	window.draw(text);
	window.draw(line);
	window.draw(valuePoint);
}

Slider::Slider(Vector2f topLeftPosition, string name, Vector2f valueRange, Font font, double initialValue) {
	this->position = topLeftPosition;
	this->name = name;
	this->sliderRange = valueRange;
	this->font = font;

	this->sliderPosition = Vector2f(position.x, position.y + 25);
	this->sliderDimensions = Vector2f(130, 3);
	if (initialValue == -1) this->sliderValue = sliderRange.x + (sliderRange.y - sliderRange.x) * 0.35;
	else this->sliderValue = initialValue;

}
