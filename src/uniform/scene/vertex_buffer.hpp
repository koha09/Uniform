#include <uniform/platform/platform.hpp>

#include <uniform/core/math/matrix.hpp>
#include <uniform/scene/gpu_buffer.hpp>

#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

class UNIFORM_API VertexBuffer : GPUBuffer
{
public:

    enum Type
    {
        Byte = 0x1400,
        UnsignedByte = 0x1401,
        Short = 0x1402,
        UnsignedShort = 1403,
        Int = 0x1404,
        UnsignedInt = 0x1405,
        Float = 0x1406,
        Double = 0x140A
    };

    VertexBuffer(uint32_t id, VertexBuffer::Type type, uint32_t size);
    VertexBuffer(uint32_t id, const void *data, VertexBuffer::Type type, uint32_t size);

    template <class _type, uint32_t _rows, uint32_t _columns>
    void set(Matrix<_type, _rows, _columns> matrix) {
        this->set_data(matrix.data());
    }

    void bind();
    void unbind();

private:

    uint32_t _vertex_id;

};

#endif