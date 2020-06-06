#pragma once

#include <uniform/platform/platform.hpp>

#include <string>

namespace Uniform
{
    class VideoMode
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

        enum Style : size_t {
            Resizable = 1 << 0,
            Maximized = 1 << 1,
            Floating = 1 << 2
        };

        Window(std::string title, VideoMode mode, size_t style);
        virtual ~Window();

        bool is_open();

        int get_width() const;
        int get_height() const;

        bool is_vsync() const;
        void set_vsync(bool enabled);

    private:

        Handle *_window;

        std::string _title;
        VideoMode _mode;
        bool _vsync;

    };
}