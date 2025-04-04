// Sphere.cpp
# define M_PI           3.14159265358979323846  /* pi */

#include "Sphere.h"
#include <vector>
#include <cmath>
Sphere::Sphere(int sectorCount, int stackCount, float radius) {
    buildSphere(sectorCount, stackCount, radius);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}
void Sphere::buildSphere(int sectorCount, int stackCount, float radius) {
    float x, y, z, xy;
    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    for (int i = 0; i <= stackCount; ++i) {
        float stackAngle = M_PI / 2 - i * stackStep;
        xy = radius * cosf(stackAngle);
        y = radius * sinf(stackAngle);
        for (int j = 0; j <= sectorCount; ++j) {
            float sectorAngle = j * sectorStep;
            x = xy * cosf(sectorAngle);
            z = xy * sinf(sectorAngle);
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }
    int k1, k2;
    for (int i = 0; i < stackCount; ++i) {
        k1 = i * (sectorCount + 1);
        k2 = k1 + sectorCount + 1;
        for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
            if (i != 0) {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }
            if (i != (stackCount - 1)) {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
}
void Sphere::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
unsigned int Sphere::getVAO() const { return VAO; }
unsigned int Sphere::getIndexCount() const { return indices.size(); }
