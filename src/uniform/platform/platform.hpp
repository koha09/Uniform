#ifndef PLATFORM_HPP
#define PLATFORM_HPP

# if defined(__linux__)
#  define UNIFORM_PLATFORM_LINUX
# elif defined(_WIN32) || defined(_WIN64)
#  define UNIFORM_PLATFORM_WINDOWS
# else
#  error UNIFORM_PLATFORM_NOT_SUPPORTED
# endif

# if defined(UNIFORM_PLATFORM_LINUX)
#  define UNIFORM_API
# elif defined(UNIFORM_PLATFORM_WINDOWS)
#  if defined(UNIFORM_LIBRARY)
#   define UNIFORM_API __declspec(dllexport)
#  else
#   define UNIFORM_API __declspec(dllimport)
#  endif
# endif

#endif