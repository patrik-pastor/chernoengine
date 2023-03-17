//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_RENDERER_API_HPP
#define CHERNOENGINE_RENDERER_API_HPP

#include <memory>

#include <glm/glm.hpp>

#include <chernoengine/renderer/vertex_array.hpp>

namespace chernoengine {

class RendererApi {
public:
    enum class API {
        None = 0, Opengl = 1
    };

    virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertex_array) = 0;

    virtual void SetClearColor(const glm::vec4 &color) = 0;

    virtual void Clear() = 0;

    static API GetApi();

private:
    static API api_;
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_API_HPP
