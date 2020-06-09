#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/core/os/keyboard.hpp>
#include <uniform/core/os/mouse.hpp>

#include <uniform/core/math/point2.hpp>
#include <uniform/core/math/size2.hpp>

#include <string>

namespace Uniform
{
    class UNIFORM_API VideoMode
    {
    public:

        VideoMode(int mode_width, int mode_height);

        int width, height;

    };

    class UNIFORM_API Window
    {
    private:

        struct Handle;

    public:

        enum Style : unsigned {
            Resizable = 1 << 0,
            Maximized = 1 << 1,
            Floating = 1 << 2
        };

        Window(std::string title, VideoMode mode, unsigned style);
        virtual ~Window();

        bool is_open();

        int get_width();
        int get_height();

        bool is_vsync();
        void set_vsync(bool enabled);

    private:

        Handle *_window;

        std::string _title;
        VideoMode _mode;
        bool _vsync;

    public:

        virtual void OnKeyboardPress(
            const Keyboard::Code,
            const Keyboard::Action
        ) { }

        virtual void OnMousePress(
            const Mouse::Code,
            const Mouse::Action
        ) { }

        virtual void OnMouseMove(const Point2i) { }

        virtual void OnWindowMove(const Point2i) { }
        virtual void OnWindowResize(const Size2i) { }

    };
}