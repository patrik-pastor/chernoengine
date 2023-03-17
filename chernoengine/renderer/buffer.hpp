//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_BUFFER_HPP
#define CHERNOENGINE_BUFFER_HPP

#include <string>
#include <vector>
#include <initializer_list>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace chernoengine {

enum class ShaderDataType {
    None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

int ShaderDataTypeSize(ShaderDataType type);

int ElementComponentCount(ShaderDataType type);

GLenum ShaderDataTypeToOpenglBaseType(ShaderDataType type);

struct BufferElement {
    BufferElement(ShaderDataType type, const std::string &name);

    std::string name;
    ShaderDataType type;
    int size;
    int offset;
    bool normalized;
    int component_count;
};

class BufferLayout {
public:
    BufferLayout() = default;

    BufferLayout(const std::initializer_list<BufferElement> &elements);

    int GetStride() const;

    std::vector<BufferElement>::iterator begin();

    std::vector<BufferElement>::iterator end();

    std::vector<BufferElement>::const_iterator begin() const;

    std::vector<BufferElement>::const_iterator end() const;

private:
    void CalculateOffsetAndStride();

    std::vector<BufferElement> elements_;
    int stride_ = 0;
};

class VertexBuffer {
public:
    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;

    virtual void Unbind() const = 0;

    virtual void SetLayout(const BufferLayout &layout) = 0;

    virtual const BufferLayout &GetLayout() const = 0;

    static VertexBuffer *Create(float *vertices, int size);
};

class IndexBuffer {
public:
    virtual ~IndexBuffer() = default;

    virtual void Bind() const = 0;

    virtual void Unbind() const = 0;

    virtual int GetCount() const = 0;

    static IndexBuffer *Create(int *indices, int count);
};

} // chernoengine

#endif //CHERNOENGINE_BUFFER_HPP
