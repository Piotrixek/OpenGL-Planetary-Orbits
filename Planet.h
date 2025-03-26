// Planet.h
#pragma once
#include <glm/glm.hpp>
class Planet {
public:
    Planet(const glm::vec3& pos, const glm::vec3& vel, float mass, float radius);
    void applyForce(const glm::vec3& force);
    void update(float dt);
    const glm::vec3& getPosition() const;
    float getMass() const;
    float getRadius() const;
    glm::vec3 position;
    glm::vec3 velocity;
    float mass;
    float radius;
private:
    glm::vec3 acceleration;
};
