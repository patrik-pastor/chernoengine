//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_OPENGL_CONTEXT_HPP
#define CHERNOENGINE_OPENGL_CONTEXT_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chernoengine/renderer/graphics_context.hpp>

namespace chernoengine {

class OpenglContext : public GraphicsContext {
public:
    explicit OpenglContext(GLFWwindow *window);

    void Init() override;

private:
    GLFWwindow *window;
};

} // chernoengine

#endif //CHERNOENGINE_OPENGL_CONTEXT_HPP
