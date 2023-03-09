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

#define BIND_EVENT_FN(x) std::bind(&chernoengine::Application::x, this, std::placeholders::_1)

namespace chernoengine {

Application::Application() {
    window = std::make_unique<LinuxWindow>(LinuxWindow());
    window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

void Application::OnEvent(const Event &e) {
    std::cout << e.ToString() << std::endl;
    //TODO: ===now===
}

void Application::Run() {
    while(is_running){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window->OnUpdate();
    }
}

} // chernoengine