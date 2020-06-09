# Uniform
[![Build Status](https://travis-ci.org/beryll1um/Uniform.svg?branch=master)](https://travis-ci.org/beryll1um/Uniform.svg?branch=master)

Simple game development framework.

## Examples
### Safe
Safe application design interface
```cpp
#include <uniform.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) { }

    bool OnUpdate(const float elapsed_time) override {
        return is_open();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}
```

### Simple
Simple event handling system
```cpp
#include <uniform.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) { }

    void OnKeyboardPress(Keyboard::Code code, Keyboard::Action action) { }

    void OnMousePress(Mouse::Code code, Mouse::Action action) { }
    void OnMouseMove(Point2i position) { }

    void OnWindowMove(Point2i position) { }
    void OnWindowResize(Size2i size) { }

    bool OnUpdate(const float elapsed_time) override {
        return is_open();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}
```

## Build
Build system implemented using CMake toolkit.