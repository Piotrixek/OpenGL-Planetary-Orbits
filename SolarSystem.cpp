// SolarSystem.cpp
#include "SolarSystem.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
SolarSystem::SolarSystem() : gravitationalConstant(0.1f), sphere(48, 24, 1.0f) {
    initPlanets();
}
void SolarSystem::initPlanets() {
    Planet sun(glm::vec3(0.0f), glm::vec3(0.0f), 1000.0f, 2.0f);
    sun.angularVelocity = 0.1f;
    sun.setColor(glm::vec3(1.0f, 0.9f, 0.2f));
    planets.push_back(sun);
    Planet planet1(glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.8f, 0.0f), 10.0f, 1.0f);
    planet1.angularVelocity = 0.5f;
    planet1.setColor(glm::vec3(0.2f, 0.7f, 1.0f));
    planets.push_back(planet1);
    Planet planet2(glm::vec3(-15.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.3f, 0.0f), 20.0f, 1.2f);
    planet2.angularVelocity = 0.3f;
    planet2.setColor(glm::vec3(0.8f, 0.3f, 0.2f));
    planets.push_back(planet2);
}
void SolarSystem::update(float dt) {
    for (size_t i = 0; i < planets.size(); i++) {
        for (size_t j = 0; j < planets.size(); j++) {
            if (i != j) {
                glm::vec3 dir = planets[j].getPosition() - planets[i].getPosition();
                float distSqr = glm::dot(dir, dir) + 0.001f;
                glm::vec3 force = (gravitationalConstant * planets[i].getMass() * planets[j].getMass() / distSqr) * glm::normalize(dir);
                planets[i].applyForce(force);
            }
        }
    }
    for (auto& p : planets) {
        p.update(dt);
    }
}
void SolarSystem::draw(unsigned int shaderProgram) {
    for (auto& p : planets) {
        glm::mat4 model = p.getModelMatrix();
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, &model[0][0]);
        glUniform3fv(glGetUniformLocation(shaderProgram, "objectColor"), 1, &p.getColor()[0]);
        sphere.draw();
    }
}
std::vector<Planet>& SolarSystem::getPlanets() { return planets; }
void SolarSystem::setGravitationalConstant(float g) { gravitationalConstant = g; }
float SolarSystem::getGravitationalConstant() const { return gravitationalConstant; }
void SolarSystem::addPlanet(const Planet& planet) { planets.push_back(planet); }
