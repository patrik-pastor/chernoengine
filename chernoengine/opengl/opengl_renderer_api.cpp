//
// Created by shepherd on 17.3.23.
//

#include <chernoengine/opengl/opengl_renderer_api.hpp>

namespace chernoengine {

void OpenglRendererApi::DrawIndexed(const std::shared_ptr<VertexArray> &vertex_array) {
    glDrawElements(GL_TRIANGLES, vertex_array->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void OpenglRendererApi::SetClearColor(const glm::vec4 &color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void OpenglRendererApi::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

} // chernoengine