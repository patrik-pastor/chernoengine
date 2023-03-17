//
// Created by shepherd on 17.3.23.
//

#include <chernoengine/renderer/vertex_array.hpp>

#include <iostream>

#include <chernoengine/renderer/renderer.hpp>
#include <chernoengine/opengl/opengl_vertex_array.hpp>

namespace chernoengine {

std::shared_ptr<VertexArray> VertexArray::Create() {
    switch (Renderer::GetRendererApi().GetApi()) {
        case RendererApi::API::None:
            std::cerr << "RendererApi::None is currently not supported\n";
            return nullptr;
        case RendererApi::API::Opengl:
            return std::make_shared<OpenglVertexArray>();
    }
    std::cerr << "Unknown RendererApi\n";
    return nullptr;
}

} // chernoengine