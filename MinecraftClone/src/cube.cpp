#include "glad/glad.h"
#include "cube.hpp"

Cube::Cube(glm::vec3 position) : position(position) {

    glGenBuffers(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    float vertices[] = {
        // Front face
        -0.5f + position.x, -0.5f + position.y, 0.5f + position.z,  // Bottom-left 0
        0.5f + position.x, -0.5f + position.y, 0.5f + position.z,   // Bottom-right 1
        0.5f + position.x, 0.5f + position.y, 0.5f + position.z,    // Top-right 2
        -0.5f + position.x, 0.5f + position.y, 0.5f + position.z,   // Top-left 3

        // Back face
        -0.5f + position.x, -0.5f + position.y, -0.5f + position.z, // Bottom-left 4
        0.5f + position.x, -0.5f + position.y, -0.5f + position.z,  // Bottom-right 5
        0.5f + position.x, 0.5f + position.y, -0.5f + position.z,   // Top-right 6
        -0.5f + position.x, 0.5f + position.y, -0.5f + position.z  // Top-left 7
    };

    unsigned int indices[] = {
        // Front face
        0, 1, 2,    // Triangle 1
        2, 3, 0,    // Triangle 2
        // Back face
        4, 5, 6,    // Triangle 1
        6, 7, 4,     // Triangle 2
        // Left face
        3, 7, 4,    // Triangle 1
        4, 0, 3,    // Triangle 2
        // Right face
        1, 5, 6,    // Triangle 1
        6, 2, 1 ,    // Triangle 2
        // Top face
        3, 2, 6,    // Triangle 1
        6, 7, 3,    // Triangle 2
        // Bottom face
        4, 5, 1,
        1, 0, 4
    };
    //
    //
    
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}
Cube::~Cube() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
GLuint Cube::getVAO() const
{
    return VAO;
}
