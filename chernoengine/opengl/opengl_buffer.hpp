//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_OPENGL_BUFFER_HPP
#define CHERNOENGINE_OPENGL_BUFFER_HPP

#include <stdint.h>

#include <chernoengine/renderer/buffer.hpp>

namespace chernoengine {

class OpenglVertexBuffer : public VertexBuffer {
public:
    OpenglVertexBuffer(float *vertices, int size);

    ~OpenglVertexBuffer() override;

    void Bind() const override;

    void Unbind() const override;

    void SetLayout(const BufferLayout &layout) override;

    const BufferLayout &GetLayout() const override;

private:
    uint32_t renderer_id_;
    BufferLayout layout_;
};

class OpenglIndexBuffer : public IndexBuffer {
public:
    OpenglIndexBuffer(int *indices, int count);

    ~OpenglIndexBuffer() override;

    void Bind() const override;

    void Unbind() const override;

    int GetCount() const override;

private:
    uint32_t renderer_id_;
    int count_;
};

} // chernoengine

#endif //CHERNOENGINE_OPENGL_BUFFER_HPP
