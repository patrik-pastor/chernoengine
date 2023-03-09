//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/renderer/opengl_context.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace chernoengine {

OpenglContext::OpenglContext(GLFWwindow *window) : window(window) {
}

void OpenglContext::Init() {
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *_, int width, int height) {
        glViewport(0, 0, width, height);
    });
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "failed to initialize GLAD";
    }
    std::cout << "Opengl Info:\n"
                 "Vendor: " << glGetString(GL_VENDOR) <<
              "\nRenderer: " << glGetString(GL_RENDERER) <<
              "\nVersion: " << glGetString(GL_VERSION) << std::endl;
}

} // chernoengine