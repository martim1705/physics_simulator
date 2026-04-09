#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "object.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 720, 480 }), "SFML works!");

    float r;
    sf::Vector2f pos;

    std::cout << "Choose a radius: ";
    std::cin >> r;
    std::cout << "Choose a x position: ";
    std::cin >> pos.x;
    std::cout << "Choose a y position: ";
    std::cin >> pos.y;

    Object object(r, pos);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            // salto só quando a tecla é premida
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                
            }
        }

        float vx = 0.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            vx = -120.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            vx = 120.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            object.setHorizontalVelocity(-900.f);
        }
        object.setHorizontalVelocity(vx);
        object.update(dt);

        window.clear();
        object.draw(window);
        window.display();
    }
}