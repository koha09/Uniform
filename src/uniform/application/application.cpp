#include <uniform/application/application.hpp>

#include <chrono>
using namespace std::chrono;

Uniform::IApplication::IApplication() {

}

Uniform::IApplication::~IApplication() {

}

void Uniform::IApplication::Run() {
    system_clock::time_point first_time;
    float elapsed_time = 1.f;

    bool atom_active = true;
    while (atom_active) {
        first_time = system_clock::now();
        atom_active = OnUpdate(elapsed_time);
        elapsed_time = (system_clock::now() - first_time).count();
    }
}