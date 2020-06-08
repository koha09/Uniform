#include <uniform/application/window/window.hpp>

#include <logger/logger.hpp>
#include <GLFW/glfw3.h>

Uniform::VideoMode::VideoMode(
    int mode_width,
    int mode_height
) : width(mode_width), height(mode_height) { }

struct Uniform::Window::Handle {
    GLFWwindow *instance;
};

Uniform::Window::Window(
    std::string title,
    VideoMode mode,
    size_t style
) : _title(title), _mode(mode), _window(new Handle) {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_RESIZABLE, (style & Style::Resizable) == Style::Resizable);
    glfwWindowHint(GLFW_MAXIMIZED, (style & Style::Maximized) == Style::Maximized);
    glfwWindowHint(GLFW_FLOATING,   (style & Style::Floating) == Style::Floating);

    _window->instance = glfwCreateWindow(mode.width, mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->instance);
    set_vsync(false);

    glfwSetWindowUserPointer(_window->instance, (void*)this);
    glfwSetKeyCallback(_window->instance, [](GLFWwindow *window, int key, int scan_code, int action, int mods) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnKeyboardPress((Keyboard::Code)key, (Keyboard::Action)action);
    });

	glfwSetCursorPosCallback(_window->instance, [](GLFWwindow *window, double position_x, double position_y) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnMouseMove(Vector2i((int)position_x, (int)position_y));
	});

	glfwSetMouseButtonCallback(_window->instance, [](GLFWwindow *window, int button, int action, int mods) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnMousePress((Mouse::Code)button, (Mouse::Action)action);
	});

	glfwSetWindowPosCallback(_window->instance, [](GLFWwindow *window, int position_x, int position_y) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnWindowMove(Vector2i(position_x, position_y));
	});

	glfwSetWindowSizeCallback(_window->instance, [](GLFWwindow *window, int width, int height) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnWindowResize(Vector2i(width, height));
	});
}

Uniform::Window::~Window() {
    glfwDestroyWindow(_window->instance);
    glfwTerminate();
    delete _window;
}

bool Uniform::Window::is_open() {
    glfwPollEvents();
	return !glfwWindowShouldClose(_window->instance);
}

int Uniform::Window::get_width() const {
    glfwGetWindowSize(_window->instance, (int*)&_mode.width, nullptr);
    return _mode.width;
}

int Uniform::Window::get_height() const{
    glfwGetWindowSize(_window->instance, nullptr, (int*)&_mode.height);
    return _mode.height;
}

bool Uniform::Window::is_vsync() const{
    return _vsync;
}

void Uniform::Window::set_vsync(bool enabled) {
    glfwSwapInterval(_vsync = enabled);
}