#include <stdexcept>

#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#define UF_EXCEPTION_INVALID_OPERATION std::runtime_error("invalid operation");
#define UF_EXCEPTION_ALREADY_EXISTS    std::runtime_error("already exists");
#define UF_EXCEPTION_OUT_OF_RANGE      std::runtime_error("out of range");
#define UF_EXCEPTION_NOT_FOUND         std::runtime_error("not found");

#define UF_EXCEPTION_CUSTOM(message) std::runtime_error(message);

#endif