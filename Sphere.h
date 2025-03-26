// Sphere.h
#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
class Sphere {
public:
    Sphere(int sectorCount = 36, int stackCount = 18, float radius = 1.0f);
    void draw();
    unsigned int getVAO() const;
    unsigned int getIndexCount() const;
private:
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    void buildSphere(int sectorCount, int stackCount, float radius);
};
