#include "object.h"

Object::Object(float radius, sf::Vector2f position) : radius(radius) {
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setOrigin({ radius, radius });
    shape.setFillColor(sf::Color(0xFF, 0xF2, 0xA6, 255));

    velocity = { 0.f, 0.f };
}

void Object::draw(sf::RenderWindow& w) const {
    w.draw(shape);
}

void Object::setVelocity(sf::Vector2f v) {
    velocity = v;
}

void Object::setHorizontalVelocity(float vx) {
    velocity.x = vx;
}

sf::Vector2f Object::getPos() const {
    return shape.getPosition();
}

sf::Vector2f Object::getVelocity() const {
    return velocity;
}

void Object::update(float dt) {
    float g = 2354.4f;
    float perda_energia = 0.7f;

    velocity.y += g * dt;

    sf::Vector2f pos = shape.getPosition();
    pos += velocity * dt;

    if (pos.y > 480.f - radius) {
        pos.y = 480.f - radius;
        velocity.y = -perda_energia * velocity.y;
    }
    else if (pos.y < radius) {
        pos.y = radius;
        velocity.y = -perda_energia * velocity.y;
    }

    if (pos.x < radius) {
        pos.x = radius;
        velocity.x = -perda_energia * velocity.x;
    }
    else if (pos.x > 720.f - radius) {
        pos.x = 720.f - radius;
        velocity.x = -perda_energia * velocity.x;
    }

    shape.setPosition(pos);
}