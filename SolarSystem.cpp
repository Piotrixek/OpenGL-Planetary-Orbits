// SolarSystem.cpp
#include "SolarSystem.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
SolarSystem::SolarSystem() : gravitationalConstant(0.1f), sphere(36, 18, 1.0f) {
    initPlanets();
}
void SolarSystem::initPlanets() {
    planets.push_back(Planet(glm::vec3(0.0f), glm::vec3(0.0f), 1000.0f, 2.0f));
    planets.push_back(Planet(glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.5f, 0.0f), 10.0f, 1.0f));
    planets.push_back(Planet(glm::vec3(-15.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), 20.0f, 1.2f));
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
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, p.getPosition());
        model = glm::scale(model, glm::vec3(p.getRadius()));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, &model[0][0]);
        sphere.draw();
    }
}
std::vector<Planet>& SolarSystem::getPlanets() { return planets; }
