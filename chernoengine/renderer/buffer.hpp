//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_BUFFER_HPP
#define CHERNOENGINE_BUFFER_HPP

namespace chernoengine {

class VertexBuffer {
public:
    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;

    virtual void Unbind() const = 0;

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
