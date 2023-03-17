//
// Created by shepherd on 17.3.23.
//

#ifndef CHERNOENGINE_OPENGL_VERTEX_ARRAY_HPP
#define CHERNOENGINE_OPENGL_VERTEX_ARRAY_HPP

#include <memory>
#include <vector>

#include <chernoengine/renderer/vertex_array.hpp>
#include <chernoengine/renderer/buffer.hpp>

namespace chernoengine {

class OpenglVertexArray : public VertexArray {
public:
    OpenglVertexArray();

    void Bind() const override;

    void Unbind() const override;

    void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) override;

    void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &buffer) override;

    const std::vector<std::shared_ptr<VertexBuffer>> &GetVertexBuffers() const override;

    const std::shared_ptr<IndexBuffer> &GetIndexBuffer() const override;

private:
    uint32_t renderer_id_;
    std::vector<std::shared_ptr<VertexBuffer>> vertex_buffers_;
    std::shared_ptr<IndexBuffer> index_buffer_;
};

} // chernoengine

#endif //CHERNOENGINE_OPENGL_VERTEX_ARRAY_HPP
