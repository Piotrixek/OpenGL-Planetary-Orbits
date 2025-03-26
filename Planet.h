// Planet.h
#pragma once
#include <glm/glm.hpp>
class Planet {
public:
    Planet(const glm::vec3& pos, const glm::vec3& vel, float mass, float radius);
    void applyForce(const glm::vec3& force);
    void update(float dt);
    void updateRotation(float dt);
    const glm::vec3& getPosition() const;
    float getMass() const;
    float getRadius() const;
    glm::mat4 getModelMatrix() const;
    void setColor(const glm::vec3& col);
    const glm::vec3& getColor() const;
    glm::vec3 position;
    glm::vec3 velocity;
    float mass;
    float radius;
    glm::vec3 rotationAxis;
    float rotationAngle;
    float angularVelocity;
private:
    glm::vec3 acceleration;
    glm::vec3 color;
};
