//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/renderer/graphics_context.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chernoengine/renderer/opengl_context.hpp>

namespace chernoengine {

GraphicsContext *GraphicsContext::Create(void *window) {
    //TODO: do it the right way
    return new OpenglContext(static_cast<GLFWwindow*>(window));
}

} // chernoengine