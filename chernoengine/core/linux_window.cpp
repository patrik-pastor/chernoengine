//
// Created by shepherd on 8.3.23.
//

#include <iostream>

#include <chernoengine/core/linux_window.hpp>
#include <chernoengine/events/application_event.hpp>
#include <chernoengine/events/key_event.hpp>
#include <chernoengine/events/mouse_event.hpp>

namespace chernoengine {

static int glfw_window_count = 0;

LinuxWindow::LinuxWindow(const WindowProps &props) {
    std::cout << "Creating window_ " << props.title << "(" << props.width << ", " << props.height << ")\n";
    data_.title = props.title;
    data_.width = props.width;
    data_.height = props.height;

    if (glfw_window_count == 0) {
        std::cout << "glfwInit\n";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwInit();
    }

    std::cout << "glfwCreateWindow\n";
    window_ = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
    glfw_window_count++;
    if (window_ == nullptr) {
        std::cerr << "failed to create GLFW window_\n";
    }

    // TODO: do it the right way (cherno using scopes, not pointers)
    context_ = dynamic_cast<OpenglContext *>(GraphicsContext::Create(window_));
    context_->Init();

    glfwSetWindowUserPointer(window_, &data_);

    glfwSetWindowSizeCallback(window_, [](GLFWwindow *window, int width, int height) {
        WindowData data = *(WindowData *) glfwGetWindowUserPointer(window);
        data.width = width;
        data.height = height;

        WindowResizeEvent event(width, height);
        data.event_callback(event);
    });

    glfwSetWindowCloseCallback(window_, [](GLFWwindow *window) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        WindowCloseEvent event;
        data.event_callback(event);
    });

    glfwSetKeyCallback(window_, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, false);
                data.event_callback(event);
                break;
            }
            case GLFW_RELEASE: {
                KeyReleasedEvent event(key);
                data.event_callback(event);
                break;
            }
            case GLFW_REPEAT: {
                KeyPressedEvent event(key, true);
                data.event_callback(event);
                break;
            }
        }
    });

    glfwSetCharCallback(window_, [](GLFWwindow *window, uint32_t codepoint) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        KeyTypedEvent event(codepoint);
        data.event_callback(event);
    });

    glfwSetMouseButtonCallback(window_, [](GLFWwindow *window, int button, int action, int mods) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        switch (action) {
            case GLFW_PRESS: {
                MouseButtonPressedEvent event(button);
                data.event_callback(event);
                break;
            }
            case GLFW_RELEASE: {
                MouseButtonReleasedEvent event(button);
                data.event_callback(event);
                break;
            }
        }
    });

    glfwSetScrollCallback(window_, [](GLFWwindow *window, double xoffset, double yoffset) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        MouseScrolledEvent event(xoffset, yoffset);
        data.event_callback(event);
    });

    glfwSetCursorPosCallback(window_, [](GLFWwindow *window, double xpos, double ypos) {
        WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
        MouseMovedEvent event(xpos, ypos);
        data.event_callback(event);
    });
}

void LinuxWindow::OnUpdate() {
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

int LinuxWindow::GetWidth() const {
    return data_.width;
}

int LinuxWindow::GetHeight() const {
    return data_.height;
}

void LinuxWindow::SetEventCallback(const Window::EventCallbackFn callback) {
    data_.event_callback = callback;
}

void *LinuxWindow::GetNativeWindow() const {
    return window_;
}

} // chernoengine