#pragma once

#include <uniform/platform/platform.hpp>

#if defined(UNIFORM_PLATFORM_LINUX)
# include <uniform/platform/linux/linux.hpp>
#elif defined(UNIFORM_PLATFORM_WINDOWS)
# include <uniform/platform/windows/windows.hpp>
#endif