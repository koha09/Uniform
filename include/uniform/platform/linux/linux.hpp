#pragma once

#include <uniform/application/application.hpp>

int main() {
    Uniform::IApplication *application = Uniform::CreateApplication();
    application->run();
    delete application;
    return 0;
}