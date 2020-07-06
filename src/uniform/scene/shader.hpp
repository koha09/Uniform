#include <uniform/platform/platform.hpp>

#include <uniform/core/runtime.hpp>
#include <uniform/core/int_types.hpp>

#include <uniform/core/math/matrix_fwd.hpp>
#include <uniform/core/math/vector_fwd.hpp>

#ifndef SHADER_HPP
#define SHADER_HPP

class UNIFORM_API Shader
{
public:

    Shader(const char *vertex_source, const char *fragment_source);

    virtual ~Shader();

    void bind();
    void unbind();

    void set_int(const std::string &name, int value);
    void set_int2(const std::string &name, const Vector<int, 2> &value);
    void set_int3(const std::string &name, const Vector<int, 3> &value);
    void set_int4(const std::string &name, const Vector<int, 4> &value);

    void set_float(const std::string &name, float value);
    void set_float2(const std::string &name, const Vector<float, 2> &value);
    void set_float3(const std::string &name, const Vector<float, 3> &value);
    void set_float4(const std::string &name, const Vector<float, 4> &value);

	void set_float3x3(const std::string &name, Matrix<float, 3, 3> &value);
	void set_float4x4(const std::string &name, Matrix<float, 4, 4> &value);

    void set_double3x3(const std::string &name, Matrix<double, 3, 3> &value);
	void set_double4x4(const std::string &name, Matrix<double, 4, 4> &value);

private:

    void throw_if_error(uint32_t id, uint32_t type);

    uint32_t _id;

};

#endif