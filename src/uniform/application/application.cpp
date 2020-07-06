#include <uniform/application/application.hpp>

#include <list>

struct Uniform::IApplication::layers_wrapper {
    mutable std::list<ILayer*> wrapped_layers;
};

Uniform::IApplication::IApplication(
    const std::string &title,
    const VideoMode &mode,
    uint32_t style
) : Window(title, mode, style), _layers(new layers_wrapper) {
    _running = true;
}

Uniform::IApplication::~IApplication() {
    delete _layers;
}

void Uniform::ILayer::OnAttach(IApplication *application) { }
void Uniform::ILayer::OnDetach() { }

void Uniform::ILayer::OnStartFrame(const nanoseconds) { }
void Uniform::ILayer::OnEndFrame(const nanoseconds) { }

void Uniform::IApplication::push_layer(ILayer *layer) {
    _layers->wrapped_layers.push_back(layer);
    layer->OnAttach(this);
}

void Uniform::IApplication::run() {
    OnCreate();
    nanoseconds elapsed_time(0);
    system_clock::time_point started_time;
    while (_running) {
        started_time = system_clock::now();

        for (auto it = _layers->wrapped_layers.begin(); it != _layers->wrapped_layers.end(); ++it) {
            (*it)->OnStartFrame(elapsed_time);
            if (!(*it)->OnUpdate(elapsed_time)) {
                (*it)->OnEndFrame(elapsed_time), (*it)->OnDetach();
                _layers->wrapped_layers.erase(it);
                continue;
            }
            (*it)->OnEndFrame(elapsed_time);
        }

        if (!OnUpdate(elapsed_time)) {
            break;
        }

        elapsed_time = (system_clock::now() - started_time);
    }
    OnClose();
}

void Uniform::IApplication::OnCreate() { }
void Uniform::IApplication::OnClose() { }