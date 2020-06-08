#include <uniform/application/application.hpp>

#include <chrono>
using namespace std::chrono;

Uniform::IApplication::IApplication(
    std::string title,
    VideoMode mode,
    size_t style
) : Window(title, mode, style) { }

Uniform::IApplication::~IApplication() { }

void Uniform::IApplication::run() {
    float elapsed_time = 1.f;
    system_clock::time_point first_time;
    for (bool atom_active = true; atom_active; first_time = system_clock::now()) {
        atom_active = OnUpdate(elapsed_time);
        elapsed_time = float((system_clock::now() - first_time).count());
    }
}