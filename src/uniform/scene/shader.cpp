#include <uniform/scene/shader.hpp>

#include <uniform/core/debug/logger.hpp>

#include <glad/glad.h>

#include <uniform/core/math/matrix.hpp>

#include <uniform/core/math/vector2.hpp>
#include <uniform/core/math/vector3.hpp>
#include <uniform/core/math/vector4.hpp>

Shader::Shader(const char *vertex_source, const char *fragment_source) {
    uint32_t vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id, 1, &vertex_source, 0);
    glCompileShader(vertex_id);
    throw_if_error(vertex_id, GL_COMPILE_STATUS);

    uint32_t fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id, 1, &fragment_source, 0);
    glCompileShader(fragment_id);
    throw_if_error(fragment_id, GL_COMPILE_STATUS);

    _id = glCreateProgram();
    glAttachShader(_id, vertex_id);
    glAttachShader(_id, fragment_id);
    glLinkProgram(_id);
    throw_if_error(_id, GL_LINK_STATUS);

    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
}

Shader::~Shader() {
    glDeleteProgram(_id);
}

void Shader::bind() {
    glUseProgram(_id);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::set_int(const std::string &name, int value) {
    glUniform1i(glGetUniformLocation(_id, name.c_str()), value);
}

void Shader::set_int2(const std::string &name, const Vector<int, 2> &value) {
    glUniform2i(glGetUniformLocation(_id, name.c_str()), value.x, value.y);
}

void Shader::set_int3(const std::string &name, const Vector<int, 3> &value) {
    glUniform3i(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z);
}

void Shader::set_int4(const std::string &name, const Vector<int, 4> &value) {
    glUniform4i(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::set_float(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(_id, name.c_str()), value);
}

void Shader::set_float2(const std::string &name, const Vector<float, 2> &value) {
    glUniform2f(glGetUniformLocation(_id, name.c_str()), value.x, value.y);
}

void Shader::set_float3(const std::string &name, const Vector<float, 3> &value) {
    glUniform3f(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z);
}

void Shader::set_float4(const std::string &name, const Vector<float, 4> &value) {
    glUniform4f(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::set_float3x3(const std::string &name, Matrix<float, 3, 3> &value) {
    glUniformMatrix3fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.data());
}

void Shader::set_float4x4(const std::string &name, Matrix<float, 4, 4> &value) {
    glUniformMatrix4fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.data());
}

void Shader::set_double3x3(const std::string &name, Matrix<double, 3, 3> &value) {
    glUniformMatrix3dv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.data());
}

void Shader::set_double4x4(const std::string &name, Matrix<double, 4, 4> &value) {
    glUniformMatrix4dv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.data());
}

void Shader::throw_if_error(uint32_t id, uint32_t type) {
    int ok = 0, size = 0;
    switch (type) {
        case(GL_LINK_STATUS): {
            glGetProgramiv(id, GL_LINK_STATUS, &ok);
            if (ok == GL_FALSE) {
                glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &size);
                std::vector<char> error(size);
                glGetProgramInfoLog(_id, size, 0, error.data());
                throw UF_EXCEPTION_CUSTOM(std::string(begin(error), end(error)));
            }
            break;
        }

        default: {
            glGetShaderiv(id, type, &ok);
            if (ok == GL_FALSE) {
                glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &size);
                std::vector<char> error(size);
                glGetShaderInfoLog(_id, size, 0, error.data());
                throw UF_EXCEPTION_CUSTOM(std::string(begin(error), end(error)));
            }
            break;
        }
    }
}