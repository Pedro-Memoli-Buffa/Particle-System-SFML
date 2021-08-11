#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "particlesystem.h"
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "vertex tutorial");
    ParticleSystem particleSystem;
    particleSystem.SetColorVariation(true);
    particleSystem.SetRadiusVariation(true);
    particleSystem.SetLifetimeVariation(true);
    particleSystem.SetPerpDirVariation(1);

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
            particleSystem.Emit(static_cast<sf::Vector2f>(Mouse::getPosition(window)), -1);
        }

        // Drawing and moving particles
        for (int i = 0; i < particleSystem.GetParticles().size(); i++) {
            window.draw(particleSystem.GetParticles()[i].GetShape());
        }

        particleSystem.ManageLifeTime();

        window.display();
    }

    return 0;
}
