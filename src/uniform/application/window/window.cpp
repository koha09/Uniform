#include <uniform/application/window/window.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Uniform::VideoMode::VideoMode(
    const int mode_width,
    const int mode_height
) : width(mode_width), height(mode_height) { }

struct Uniform::Window::window_wrapper {
    GLFWwindow *wrapped_window;
};

Uniform::Window::Window(
    const std::string &title,
    const VideoMode &mode,
    uint32_t style
) : _title(title), _mode(mode), _window(new window_wrapper) {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_RESIZABLE, (style & Style::Resizable) == Style::Resizable);
    glfwWindowHint(GLFW_MAXIMIZED, (style & Style::Maximized) == Style::Maximized);
    glfwWindowHint(GLFW_FLOATING,   (style & Style::Floating) == Style::Floating);

    _window->wrapped_window = glfwCreateWindow(mode.width, mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->wrapped_window);
    set_vsync(false);

    if (!gladLoadGL()) {
        exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(_window->wrapped_window, (void*)this);
    glfwSetKeyCallback(_window->wrapped_window, [](GLFWwindow *window, int key, int scan_code, int action, int mods) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnKeyboardPress((Keyboard::Code)key, (Keyboard::Action)action);
    });

    glfwSetMouseButtonCallback(_window->wrapped_window, [](GLFWwindow *window, int button, int action, int mods) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnMousePress((Mouse::Code)button, (Mouse::Action)action);
	});

	glfwSetCursorPosCallback(_window->wrapped_window, [](GLFWwindow *window, double position_x, double position_y) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnMouseMove(Vector2i((int)position_x, (int)position_y));
	});

	glfwSetWindowPosCallback(_window->wrapped_window, [](GLFWwindow *window, int position_x, int position_y) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnWindowMove(Point2i(position_x, position_y));
	});

	glfwSetWindowSizeCallback(_window->wrapped_window, [](GLFWwindow *window, int width, int height) -> void {
        reinterpret_cast<Window*>(glfwGetWindowUserPointer(window))->OnWindowResize(Size2i(width, height));
	});
}

Uniform::Window::~Window() {
    glfwDestroyWindow(_window->wrapped_window);
    glfwTerminate();
    delete _window;
}

Size2i Uniform::Window::get_size() const {
    glfwGetWindowSize(_window->wrapped_window, (int*)&_mode.width, (int*)&_mode.height);
    return Size2i(_mode.width, _mode.height);
}

void Uniform::Window::set_size(Size2i size) {
    glfwSetWindowSize(_window->wrapped_window, size.x, size.y);
}

Point2i Uniform::Window::get_position() const {
    Point2i point;
    glfwGetWindowPos(_window->wrapped_window, (int*)&point.x, (int*)&point.y);
    return point;
}

void Uniform::Window::set_position(Point2i point) {
    glfwSetWindowPos(_window->wrapped_window, point.x, point.y);
}

bool Uniform::Window::is_vsync() const {
    return _vsync;
}

void Uniform::Window::set_vsync(bool enabled) {
    glfwSwapInterval(_vsync = enabled);
}

void *Uniform::Window::get_handle() {
    return (void*)_window->wrapped_window;
}

void Uniform::Window::swap_buffers() {
    glfwSwapBuffers(_window->wrapped_window);
}

bool Uniform::Window::poll_events() {
    glfwPollEvents();
	return !glfwWindowShouldClose(_window->wrapped_window);
}

Keyboard::Action Uniform::Window::keyboard_pressed(Keyboard::Code code) {
    return (Keyboard::Action)glfwGetKey(_window->wrapped_window, (int)code);
}