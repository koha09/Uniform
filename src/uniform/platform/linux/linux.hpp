#include <uniform/application/application.hpp>

#ifndef LINUX_HPP
#define LINUX_HPP

int main() {
    Uniform::IApplication *application = Uniform::CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif