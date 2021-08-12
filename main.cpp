#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "particlesystem.h"
#include "slider.h"
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1100, 700), "vertex tutorial");
    ParticleSystem particleSystem;
    particleSystem.SetColorVariation(true);
    particleSystem.SetRadiusVariation(true);
    particleSystem.SetLifetimeVariation(true);

    bool firstFrame = true;

    // Slider objects    Slider(Vector2f topLeftPosition, string name, Vector2f valueRange, Font font)
    Font reemFont;
    reemFont.loadFromFile("ReemKufi.ttf");
    
    double sliderX = 20; double sliderInitialY = 30; double sliderSeparation = 55;
    Slider radiusSlider(Vector2f(sliderX, sliderInitialY), "Part. radius", Vector2f(1, 10), reemFont, 3);
    Slider lifetimeSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation), "Part. lifetime", Vector2f(1, 4), reemFont, 1.5);
    Slider speedSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 2), "Part. speed", Vector2f(1, 5), reemFont, 2);
    Slider variationSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 3), "Part. variation", Vector2f(0, 15), reemFont, 0);
    Slider emissionRateSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 4), "Emission rate", Vector2f(1, 8), reemFont, 2);
    Slider angleSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 5), "Emission angle", Vector2f(-2.5, 390), reemFont, -2);
    Slider radiusVariationSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 6), "Radius variation", Vector2f(0, 1), reemFont, 1);
    Slider transparencySlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 7), "Transparency", Vector2f(0, 1), reemFont, 0);
    Slider colorSlider(Vector2f(sliderX, sliderInitialY + sliderSeparation * 8), "Color", Vector2f(-5, 100), reemFont, -2);

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();

        // Emission manager
        if (Mouse::isButtonPressed(Mouse::Left)) {
            particleSystem.Emit(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
        }

        // Drawing and moving particles
        for (int i = 0; i < particleSystem.GetParticles().size(); i++) {
            window.draw(particleSystem.GetParticles()[i].GetShape());
        }

        particleSystem.ManageLifeTime();

        // Slider management
        if (Mouse::isButtonPressed(Mouse::Right) || firstFrame) {
            radiusSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetRadius(radiusSlider.getValue());

            lifetimeSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetMaxLifetime(lifetimeSlider.getValue() * 60);

            speedSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetSpeed(speedSlider.getValue());

            variationSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetPerpDirVariation(variationSlider.getValue());

            emissionRateSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetEmission(emissionRateSlider.getValue());

            angleSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            particleSystem.SetAngle(angleSlider.getValue());

            radiusVariationSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            if ((int)radiusVariationSlider.getValue() == 0) {
                particleSystem.SetRadiusVariation(false);
            }
            else {
                particleSystem.SetRadiusVariation(true);
            }

            transparencySlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            if ((int)transparencySlider.getValue() == 0) {
                particleSystem.SetTransparency(false);
            }
            else {
                particleSystem.SetTransparency(true);
            }

            colorSlider.setSlider(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
            if (colorSlider.getValue() < 0) {
                particleSystem.SetColorVariation(true);
            }
            else if (colorSlider.getValue() > 100) {
                particleSystem.SetColorVariation(false);
                particleSystem.SetColor(Color::White);
            }
            else {
                particleSystem.SetColorVariation(false);
                Color newColor = rgb(colorSlider.getValue() / 100);
                particleSystem.SetColor(newColor);
            }
        }

        radiusSlider.draw(window);
        lifetimeSlider.draw(window);
        speedSlider.draw(window);
        variationSlider.draw(window);
        emissionRateSlider.draw(window);
        angleSlider.draw(window);
        radiusVariationSlider.draw(window);
        transparencySlider.draw(window);
        colorSlider.draw(window);

        window.display();

        if (firstFrame) firstFrame = false;
    }

    return 0;
}
