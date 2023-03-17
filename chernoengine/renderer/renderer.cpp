//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/renderer/renderer.hpp>

#include <chernoengine/renderer/renderer_command.hpp>

namespace chernoengine {

Renderer::SceneData *Renderer::scene_data_ = new SceneData;

RendererApi::API Renderer::GetRendererApi() {
    return RendererApi::GetApi();
}

void Renderer::Submit(const std::shared_ptr<VertexArray> &vertex_array) {
    vertex_array->Bind();
    RendererCommand::DrawIndexed(vertex_array);
}

void Renderer::BeginScene(const OrthographicCamera& camera) {
    scene_data_->view_projection_matrix = camera.GetViewProjectionMatrix();
}

void Renderer::EndScene() {

}

} // chernoengine