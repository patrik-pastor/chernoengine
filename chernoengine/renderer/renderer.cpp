//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/renderer/renderer.hpp>

#include <chernoengine/renderer/renderer_command.hpp>

namespace chernoengine {

RendererApi::API Renderer::GetRendererApi() {
    return RendererApi::GetApi();
}

void Renderer::Submit(const std::shared_ptr<VertexArray> &vertex_array) {
    vertex_array->Bind();
    RendererCommand::DrawIndexed(vertex_array);
}

} // chernoengine