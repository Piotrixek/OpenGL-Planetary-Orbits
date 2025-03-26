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
private:
    std::vector<Planet> planets;
    float gravitationalConstant;
    Sphere sphere;
    void initPlanets();
};
