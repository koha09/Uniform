#include <uniform/application/application.hpp>

#include <chrono>
using namespace std::chrono;

Uniform::IApplication::IApplication(
    std::string title,
    VideoMode mode,
    size_t style
) : Window(title, mode, style) {
    _running = true;
}

void Uniform::IApplication::push_layer(ILayer *layer) {
    _layers.push_back(layer);
}

void Uniform::IApplication::run() {
    int64_t elapsed_time = 1;
    system_clock::time_point first_time;
    while (_running) {
        first_time = system_clock::now();

        for (auto it = _layers.begin(); it != _layers.end(); ++it) {
            if (!(*it)->OnUpdate(elapsed_time)) {
                _layers.erase(it);
            }
        }

        if (!OnUpdate(elapsed_time)) {
            break;
        }

        elapsed_time = (system_clock::now() - first_time).count();
    }
}