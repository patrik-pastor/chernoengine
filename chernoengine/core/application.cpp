//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/core/application.hpp>

#include <memory>
#include <functional>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chernoengine/core/linux_window.hpp>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace chernoengine {

Application::Application() {
    window_ = new LinuxWindow;
    window_->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

void Application::OnEvent(Event &e) {
    std::cout << e.ToString() << std::endl;
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
}

void Application::Run() {
    while (IsRunning()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
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

} // chernoengine