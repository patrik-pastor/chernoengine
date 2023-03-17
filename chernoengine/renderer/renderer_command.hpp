//
// Created by shepherd on 17.3.23.
//

#ifndef CHERNOENGINE_RENDERER_COMMAND_HPP
#define CHERNOENGINE_RENDERER_COMMAND_HPP

#include <memory>

#include <chernoengine/renderer/renderer_api.hpp>

namespace chernoengine {

class RendererCommand {
public:
    static void SetClearColor(const glm::vec4 &color);

    static void Clear();

    static void DrawIndexed(const std::shared_ptr<VertexArray> &vertex_array);

private:
    static RendererApi *renderer_api_;
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_COMMAND_HPP
