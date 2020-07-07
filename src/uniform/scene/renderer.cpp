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

void UNIFORM_API Uniform::Renderer::DrawArray(Primitives type, uint32_t first, uint32_t count) {
    glDrawArrays(type, first, count);
}