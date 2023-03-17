//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_RENDERER_HPP
#define CHERNOENGINE_RENDERER_HPP

#include <glm/glm.hpp>

#include <chernoengine/renderer/renderer_api.hpp>
#include <chernoengine/renderer/orthographic_camera.hpp>

namespace chernoengine {

class Renderer {
public:
    static RendererApi::API GetRendererApi();

    static void BeginScene(const OrthographicCamera& camera);

    static void EndScene();

    static void Submit(const std::shared_ptr<VertexArray>& vertex_array);

private:
    struct SceneData {
        glm::mat4 view_projection_matrix;
    };
    static SceneData *scene_data_;
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_HPP
