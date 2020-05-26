#pragma once

#if defined(_WIN32) || defined(_WIN64)
# define UNIFORM_PLATFORM_WINDOWS
#endif

#if defined(UNIFORM_PLATFORM_WINDOWS)
# if defined(UNIFORM_LIBRARY)
#  define UNIFORM_API __declspec(dllexport)
# else
#  define UNIFORM_API __declspec(dllimport)
# endif
#else
# error UNIFORM_PLATFORM_NOT_SUPPORTED
#endif