//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/core/application.hpp>

#include <functional>
#include <iostream>

#include <glad/glad.h>

#include <chernoengine/core/linux_window.hpp>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace chernoengine {

Application *Application::application_instance_ = nullptr;

Application::Application() {
    if (application_instance_ != nullptr) {
        std::cerr << "Application already exists!\n";
    }
    application_instance_ = this;

    window_ = new LinuxWindow;
    window_->SetEventCallback(BIND_EVENT_FN(OnEvent));

    imgui_layer_ = new ImguiLayer;
    PushOverlay(imgui_layer_);
}

void Application::OnEvent(Event &e) {
    std::cout << e.ToString() << std::endl;
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    for (auto it = layer_stack_.end(); it != layer_stack_.begin();) {
        (*--it)->OnEvent(e);
        if (e.handled_) {
            break;
        }
    }
}

void Application::Run() {
    while (IsRunning()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (Layer *layer: layer_stack_)
            layer->OnUpdate();

        imgui_layer_->Begin();
        for (Layer *layer: layer_stack_)
            layer->OnImguiRender();
        imgui_layer_->End();


        window_->OnUpdate();
    }
}

bool Application::IsRunning() const {
    return running_;
}

void Application::SetRunning(bool running) {
    running_ = running;
}

bool Application::OnWindowClose(WindowCloseEvent &e) {
    SetRunning(false);
    return true;
}

void Application::PushLayer(Layer *layer) {
    layer_stack_.PushLayer(layer);
    layer->OnAttach();
}

void Application::PushOverlay(Layer *layer) {
    layer_stack_.PushOverlay(layer);
    layer->OnAttach();
}

Application &Application::GetApplicationInstance() {
    return *application_instance_;
}

Window &Application::GetWindow() const {
    return *window_;
}


} // chernoengine