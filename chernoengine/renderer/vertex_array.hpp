//
// Created by shepherd on 17.3.23.
//

#ifndef CHERNOENGINE_VERTEX_ARRAY_HPP
#define CHERNOENGINE_VERTEX_ARRAY_HPP

#include <memory>

#include <chernoengine/renderer/buffer.hpp>

namespace chernoengine {

class VertexArray {
public:
    static std::shared_ptr<VertexArray> Create();

    virtual void Bind() const = 0;

    virtual void Unbind() const = 0;

    virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) = 0;

    virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) = 0;
};

} // chernoengine

#endif //CHERNOENGINE_VERTEX_ARRAY_HPP
