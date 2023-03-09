//
// Created by shepherd on 8.3.23.
//

#include <iostream>

#include <chernoengine/core/linux_window.hpp>

namespace chernoengine {

static int glfw_window_count = 0;

LinuxWindow::LinuxWindow(const WindowProps &props) {
    data.title = props.title;
    data.width = props.width;
    data.height = props.height;

    if (glfw_window_count == 0) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwInit();
        // TODO rest
    }

    window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        std::cerr << "failed to create GLFW window\n";
    }

    // TODO: do it the right way (cherno using scopes, not pointers)
    context = dynamic_cast<OpenglContext *>(GraphicsContext::Create(window));
    context->Init();
}

void LinuxWindow::OnUpdate() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int LinuxWindow::getWidth() const {
    return data.width;
}

int LinuxWindow::getHeight() const {
    return data.height;
}

GLFWwindow *LinuxWindow::getWindow() const {
    return window;
}

void LinuxWindow::SetEventCallback(const Window::EventCallbackFn callback) {
    data.event_callback = callback;
}

} // chernoengine