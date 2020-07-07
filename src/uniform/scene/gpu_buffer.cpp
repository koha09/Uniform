#include <uniform/scene/gpu_buffer.hpp>

#include <glad/glad.h>

GPUBuffer::GPUBuffer(uint32_t size) {
    glGenBuffers(1, &_id);
    bind();
    glBufferData(GL_ARRAY_BUFFER, _size = size, 0, GL_STATIC_DRAW);
}

GPUBuffer::GPUBuffer(const void *data, uint32_t size) {
    glGenBuffers(1, &_id);
    bind();
    glBufferData(GL_ARRAY_BUFFER, _size = size, data, GL_STATIC_DRAW);
}

GPUBuffer::~GPUBuffer() {
    glDeleteBuffers(1, &_id);
}

void GPUBuffer::set_data(const void *data) {
    bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, _size, data);
}

uint32_t GPUBuffer::get_size() const {
    return _size;
}

void GPUBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void GPUBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
