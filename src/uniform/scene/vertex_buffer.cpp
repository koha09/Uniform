#include <uniform/scene/vertex_buffer.hpp>

#include <glad/glad.h>

VertexBuffer::VertexBuffer(uint32_t id, VertexBuffer::Type type, uint32_t size) : GPUBuffer(size) {
    glVertexAttribPointer(_vertex_id = id, 2, type, false, 0, 0);
}

VertexBuffer::VertexBuffer(uint32_t id, const void *data, VertexBuffer::Type type, uint32_t size) : GPUBuffer(data, size) {
    glVertexAttribPointer(_vertex_id = id, 2, type, false, 0, 0);
}

void VertexBuffer::bind() {
    glEnableVertexAttribArray(_vertex_id);
}

void VertexBuffer::unbind() {
    glDisableVertexAttribArray(_vertex_id);
}