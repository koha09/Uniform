#include <uniform/platform/platform.hpp>
#include <uniform/core/int_types.hpp>

#include <uniform/core/math/matrix_fwd.hpp>

#ifndef BUFFER_HPP
#define BUFFER_HPP

class UNIFORM_API GPUBuffer
{
public:

    GPUBuffer(uint32_t size);
    GPUBuffer(const void *data, uint32_t size);

    virtual ~GPUBuffer();

    void set_data(const void *data);

    uint32_t get_size() const;

    void bind() const;
    void unbind() const;

private:

    uint32_t _id, _size;

};

#endif