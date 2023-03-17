//
// Created by shepherd on 17.3.23.
//

#ifndef CHERNOENGINE_OPENGL_RENDERER_API_HPP
#define CHERNOENGINE_OPENGL_RENDERER_API_HPP

#include <chernoengine/renderer/renderer_api.hpp>

namespace chernoengine {

class OpenglRendererApi : public RendererApi {
public:
    void DrawIndexed(const std::shared_ptr<VertexArray> &vertex_array) override;

    void SetClearColor(const glm::vec4 &color) override;

    void Clear() override;
};

} // chernoengine

#endif //CHERNOENGINE_OPENGL_RENDERER_API_HPP
