//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/renderer/buffer.hpp>

#include <iostream>

#include <chernoengine/renderer/renderer.hpp>
#include <chernoengine/opengl/opengl_buffer.hpp>

namespace chernoengine {

VertexBuffer *VertexBuffer::Create(float *vertices, int size) {
    switch (Renderer::GetRendererApi().GetApi()) {
        case RendererApi::API::None:
            std::cerr << "RendererApi::None is currently not supported\n";
            return nullptr;
        case RendererApi::API::Opengl:
            return new OpenglVertexBuffer(vertices, size);
        default:
            std::cerr << "Unknown RendererApi\n";
            return nullptr;
    }
}

IndexBuffer *IndexBuffer::Create(int *indices, int count) {
    switch (Renderer::GetRendererApi().GetApi()) {
        case RendererApi::API::None:
            std::cerr << "RendererApi::None is currently not supported\n";
            return nullptr;
        case RendererApi::API::Opengl:
            return new OpenglIndexBuffer(indices, count);
        default:
            std::cerr << "Unknown RendererApi\n";
            return nullptr;
    }
}

} // chernoengine