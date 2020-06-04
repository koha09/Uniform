#include <uniform/application/window/window.hpp>

#include <logger/logger.hpp>
#include <GLFW/glfw3.h>

struct Uniform::Window::Handle {
    GLFWwindow *instance;
};

Uniform::Window::Window(
    std::string title,
    VideoMode mode
) : _title(title), _mode(mode), _window(new Handle) {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    _window->instance = glfwCreateWindow(mode.width, mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->instance);
}

Uniform::Window::~Window() {
    glfwDestroyWindow(_window->instance), glfwTerminate();
}

bool Uniform::Window::is_open() {
    glfwPollEvents();
	return !glfwWindowShouldClose(_window->instance);
}