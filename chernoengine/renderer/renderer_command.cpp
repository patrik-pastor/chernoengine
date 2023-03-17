//
// Created by shepherd on 17.3.23.
//

#include <chernoengine/renderer/renderer_command.hpp>

#include <chernoengine/opengl/opengl_renderer_api.hpp>

namespace chernoengine {

RendererApi *RendererCommand::renderer_api_ = new OpenglRendererApi();

void RendererCommand::SetClearColor(const glm::vec4 &color) {
    renderer_api_->SetClearColor(color);
}

void RendererCommand::Clear() {
    renderer_api_->Clear();
}

void RendererCommand::DrawIndexed(const std::shared_ptr<VertexArray> &vertex_array) {
    renderer_api_->DrawIndexed(vertex_array);
}

} // chernoengine