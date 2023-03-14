//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/opengl/opengl_buffer.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace chernoengine {

OpenglVertexBuffer::OpenglVertexBuffer(float *vertices, int size) {
    glGenBuffers(1, &renderer_id_);
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenglVertexBuffer::~OpenglVertexBuffer() {
    glDeleteBuffers(1, &renderer_id_);
}

void OpenglVertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
}

void OpenglVertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

OpenglIndexBuffer::OpenglIndexBuffer(int *indices, int count) : count_(count) {
    glGenBuffers(1, &renderer_id_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(int), indices, GL_STATIC_DRAW);
}

OpenglIndexBuffer::~OpenglIndexBuffer() {
    glDeleteBuffers(1, &renderer_id_);
}

void OpenglIndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
}

void OpenglIndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int OpenglIndexBuffer::GetCount() const {
    return count_;
}

} // chernoengine