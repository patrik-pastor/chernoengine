//
// Created by shepherd on 17.3.23.
//

#include <chernoengine/opengl/opengl_vertex_array.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace chernoengine {

OpenglVertexArray::OpenglVertexArray() {
    glGenVertexArrays(1, &renderer_id_);
}

void OpenglVertexArray::Bind() const {
    glBindVertexArray(renderer_id_);
}

void OpenglVertexArray::Unbind() const {
    glBindVertexArray(0);
}

void OpenglVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &buffer) {
    glBindVertexArray(renderer_id_);
    buffer->Bind();

    const BufferLayout &layout = buffer->GetLayout();
    int index = 0;
    for (const BufferElement &element: layout) {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(
                index,
                element.component_count,
                ShaderDataTypeToOpenglBaseType(element.type),
                element.normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                reinterpret_cast<const void *>(element.offset)
        );
        index++;
    }

    vertex_buffers_.push_back(buffer);
}

void OpenglVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &buffer) {
    glBindVertexArray(renderer_id_);
    buffer->Bind();
    index_buffer_ = buffer;
}

const std::vector<std::shared_ptr<VertexBuffer>> &OpenglVertexArray::GetVertexBuffers() const {
    return vertex_buffers_;
}

const std::shared_ptr<IndexBuffer> &OpenglVertexArray::GetIndexBuffer() const {
    return index_buffer_;
}

} // chernoengine