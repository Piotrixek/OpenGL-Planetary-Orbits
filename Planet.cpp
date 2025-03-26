// Planet.cpp
#include "Planet.h"
Planet::Planet(const glm::vec3& pos, const glm::vec3& vel, float mass, float radius)
    : position(pos), velocity(vel), mass(mass), radius(radius), acceleration(glm::vec3(0.0f)) {}
void Planet::applyForce(const glm::vec3& force) {
    acceleration += force / mass;
}
void Planet::update(float dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
    acceleration = glm::vec3(0.0f);
}
const glm::vec3& Planet::getPosition() const { return position; }
float Planet::getMass() const { return mass; }
float Planet::getRadius() const { return radius; }
