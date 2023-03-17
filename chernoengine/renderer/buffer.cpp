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

int ShaderDataTypeSize(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:
            return 4;
        case ShaderDataType::Float2:
            return 4 * 2;
        case ShaderDataType::Float3:
            return 4 * 3;
        case ShaderDataType::Float4:
            return 4 * 4;
        case ShaderDataType::Mat3:
            return 4 * 3 * 3;
        case ShaderDataType::Mat4:
            return 4 * 4 * 4;
        case ShaderDataType::Int:
            return 4;
        case ShaderDataType::Int2:
            return 4 * 2;
        case ShaderDataType::Int3:
            return 4 * 3;
        case ShaderDataType::Int4:
            return 4 * 4;
        case ShaderDataType::Bool:
            return 1;
    }

    std::cerr << "Unknown ShaderDataType\n";
    return -1;
}

int ElementComponentCount(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:
            return 1;
        case ShaderDataType::Float2:
            return 2;
        case ShaderDataType::Float3:
            return 3;
        case ShaderDataType::Float4:
            return 4;
        case ShaderDataType::Mat3:
            return 3; // 3* float3
        case ShaderDataType::Mat4:
            return 4; // 4* float4
        case ShaderDataType::Int:
            return 1;
        case ShaderDataType::Int2:
            return 2;
        case ShaderDataType::Int3:
            return 3;
        case ShaderDataType::Int4:
            return 4;
        case ShaderDataType::Bool:
            return 1;
    }
    std::cerr << "Unknown ShaderDataType\n";
    return -1;
}

GLenum ShaderDataTypeToOpenglBaseType(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::Float:
            return GL_FLOAT;
        case ShaderDataType::Float2:
            return GL_FLOAT;
        case ShaderDataType::Float3:
            return GL_FLOAT;
        case ShaderDataType::Float4:
            return GL_FLOAT;
        case ShaderDataType::Mat3:
            return GL_FLOAT;
        case ShaderDataType::Mat4:
            return GL_FLOAT;
        case ShaderDataType::Int:
            return GL_INT;
        case ShaderDataType::Int2:
            return GL_INT;
        case ShaderDataType::Int3:
            return GL_INT;
        case ShaderDataType::Int4:
            return GL_INT;
        case ShaderDataType::Bool:
            return GL_BOOL;
    }
    std::cerr << "Unknown ShaderDataType\n";
    return -1;
}

BufferElement::BufferElement(ShaderDataType type, const std::string &name) :
        type(type),
        name(name),
        size(ShaderDataTypeSize(type)),
        offset(0),
        normalized(false),
        component_count(ElementComponentCount(type)) {}

void BufferLayout::CalculateOffsetAndStride() {
    stride_ = 0;
    int offset = 0;
    for (BufferElement &element: elements_) {
        element.offset = offset;
        offset += element.size;
        stride_ += element.size;
    }
}

BufferLayout::BufferLayout(const std::initializer_list<BufferElement> &elements) : elements_(elements) {
    CalculateOffsetAndStride();
}

int BufferLayout::GetStride() const {
    return stride_;
}

std::vector<BufferElement>::iterator BufferLayout::begin() { return elements_.begin(); }

std::vector<BufferElement>::iterator BufferLayout::end() { return elements_.end(); }

std::vector<BufferElement>::const_iterator BufferLayout::begin() const { return elements_.begin(); }

std::vector<BufferElement>::const_iterator BufferLayout::end() const { return elements_.end(); }

} // chernoengine