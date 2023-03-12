//
// Created by shepherd on 11.3.23.
//

#include <chernoengine/core/input.hpp>

#include <chernoengine/core/application.hpp>

namespace chernoengine {

glm::vec2 Input::GetMousePosition() {
    auto window = (GLFWwindow *) Application::GetApplicationInstance().GetWindow().GetNativeWindow();
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return {xpos, ypos};
}

} // chernoengine