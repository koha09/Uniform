#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/application/window/video_mode.hpp>

#include <string>

namespace Uniform 
{
    class UNIFORM_API Window
    {
    private:

        struct Handle;

    public:

        Window(std::string title, VideoMode mode);
        virtual ~Window();

        bool is_open();
    
    private:

        Handle *_window;

        std::string _title;
        VideoMode _mode;

    };
}