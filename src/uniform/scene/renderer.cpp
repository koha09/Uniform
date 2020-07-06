#include <uniform/scene/renderer.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Uniform::Renderer::SetViewport(Point2i position, Size2i size) {
    glViewport(position.x, position.y, size.x, size.y);
}

void Uniform::Renderer::SetClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Uniform::Renderer::Clear(uint32_t mask) {
    glClear(mask);
}