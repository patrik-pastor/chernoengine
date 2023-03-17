//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_RENDERER_HPP
#define CHERNOENGINE_RENDERER_HPP

#include <chernoengine/renderer/renderer_api.hpp>

namespace chernoengine {

class Renderer {
public:
    static RendererApi::API GetRendererApi();

    static void Submit(const std::shared_ptr<VertexArray> &vertex_array);
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_HPP
