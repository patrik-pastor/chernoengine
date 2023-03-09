//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_LINUX_WINDOW_HPP
#define CHERNOENGINE_LINUX_WINDOW_HPP

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chernoengine/core/window.hpp>
#include <chernoengine/renderer/opengl_context.hpp>

namespace chernoengine {

class LinuxWindow : public Window{
public:
    explicit LinuxWindow(const WindowProps& props = {});

    ~LinuxWindow() override = default;

    void OnUpdate() override;

    int getWidth() const override;

    int getHeight() const override;

    void SetEventCallback(const EventCallbackFn callback) override;

    //TODO: remove this
    GLFWwindow *getWindow() const;

private:
    GLFWwindow *window;
    OpenglContext *context;
    struct WindowData {
        std::string title;
        int width;
        int height;
        EventCallbackFn event_callback;
    } data;
};

} // chernoengine

#endif //CHERNOENGINE_LINUX_WINDOW_HPP
