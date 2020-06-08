#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/core/os/keyboard.hpp>
#include <uniform/core/os/mouse.hpp>

#include <uniform/core/math/vector2.hpp>

namespace Uniform
{
    class UNIFORM_API EventDispatcher
    {
    public:

        virtual void OnKeyboardPress(Keyboard::Code code, Keyboard::Action action) { }

        virtual void OnMousePress(Mouse::Code code, Mouse::Action action) { }
        virtual void OnMouseMove(Vector2i position) { }

        virtual void OnWindowMove(Vector2i position) { }
        virtual void OnWindowResize(Vector2i size) { }

    };

}