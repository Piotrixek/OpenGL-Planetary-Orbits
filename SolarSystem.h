// SolarSystem.h
#pragma once
#include <vector>
#include "Planet.h"
#include "Sphere.h"
class SolarSystem {
public:
    SolarSystem();
    void update(float dt);
    void draw(unsigned int shaderProgram);
    std::vector<Planet>& getPlanets();
    void setGravitationalConstant(float g);
    float getGravitationalConstant() const;
    void addPlanet(const Planet& planet);
private:
    std::vector<Planet> planets;
    float gravitationalConstant;
    Sphere sphere;
    void initPlanets();
};
