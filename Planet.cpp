// Planet.cpp
#include "Planet.h"
#include <glm/gtc/matrix_transform.hpp>
Planet::Planet(const glm::vec3& pos, const glm::vec3& vel, float mass, float radius)
    : position(pos), velocity(vel), mass(mass), radius(radius), acceleration(glm::vec3(0.0f)),
    rotationAxis(glm::vec3(0.0f, 1.0f, 0.0f)), rotationAngle(0.0f), angularVelocity(0.0f), color(glm::vec3(1.0f)) {}
void Planet::applyForce(const glm::vec3& force) {
    acceleration += force / mass;
}
void Planet::update(float dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
    acceleration = glm::vec3(0.0f);
    updateRotation(dt);
}
void Planet::updateRotation(float dt) {
    rotationAngle += angularVelocity * dt;
}
const glm::vec3& Planet::getPosition() const {
    return position;
}
float Planet::getMass() const {
    return mass;
}
float Planet::getRadius() const {
    return radius;
}
glm::mat4 Planet::getModelMatrix() const {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::rotate(model, rotationAngle, rotationAxis);
    model = glm::scale(model, glm::vec3(radius));
    return model;
}
void Planet::setColor(const glm::vec3& col) {
    color = col;
}
const glm::vec3& Planet::getColor() const {
    return color;
}
