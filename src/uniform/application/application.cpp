#include <uniform/application/application.hpp>

#include <chrono>
using namespace std::chrono;

Uniform::IApplication::IApplication(
    const std::string title,
    const VideoMode mode,
    const size_t style
) : Window(title, mode, style) {
    _running = true;
}

void Uniform::ILayer::OnAttach(IApplication *application) { }
void Uniform::ILayer::OnDetach() { }

void Uniform::ILayer::OnStartFrame(const int64_t) { }
void Uniform::ILayer::OnEndFrame(const int64_t) { }

void Uniform::IApplication::push_layer(ILayer *layer) {
    _layers.push_back(layer);
    layer->OnAttach(this);
}

void Uniform::IApplication::run() {
    int64_t elapsed_time = 1;
    system_clock::time_point first_time;
    while (_running) {
        first_time = system_clock::now();

        for (auto it = _layers.begin(); it != _layers.end(); ++it) {
            (*it)->OnStartFrame(elapsed_time);
            if (!(*it)->OnUpdate(elapsed_time)) {
                (*it)->OnEndFrame(elapsed_time), (*it)->OnDetach();
                _layers.erase(it);
                continue;
            }
            (*it)->OnEndFrame(elapsed_time);
        }

        if (!OnUpdate(elapsed_time)) {
            break;
        }

        elapsed_time = (system_clock::now() - first_time).count();
    }
}