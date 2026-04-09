#pragma once
#include <SFML/Graphics.hpp>

class Object {
public:
    Object(float radius, sf::Vector2f position);

    void update(float dt);
    void draw(sf::RenderWindow& w) const;

    void setVelocity(sf::Vector2f v);
    void setHorizontalVelocity(float vx);

    sf::Vector2f getPos() const;
    sf::Vector2f getVelocity() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float radius;
};