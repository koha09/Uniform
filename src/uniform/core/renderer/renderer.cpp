#include <uniform/core/renderer/renderer.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Uniform::Renderer::SetClearColor(float r, float g, float b) {
    glClearColor(r, g, b, 1.f);
}

void Uniform::Renderer::Clear(unsigned mask) {
    glClear(mask);
}