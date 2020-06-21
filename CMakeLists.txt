cmake_minimum_required(VERSION 3.12)

project(Uniform VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

# Working directories
set(UNIFORM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(UNIFORM_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(UNIFORM_TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(UNIFORM_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

# Connection of special directories
include_directories("${UNIFORM_INCLUDE_DIR}/")

# Search all source files
file(GLOB_RECURSE UNIFORM_SRC_FILES
    "${UNIFORM_INCLUDE_DIR}/*.hpp"
    "${UNIFORM_SRC_DIR}/*.cpp"
)

# Search all dependencies files
file(GLOB_RECURSE UNIFORM_VENDOR_FILES
    "${UNIFORM_VENDOR_DIR}/*.hpp"
    "${UNIFORM_VENDOR_DIR}/*.h"
    "${UNIFORM_VENDOR_DIR}/*.cpp"
    "${UNIFORM_VENDOR_DIR}/*.c"
)

# Project builing
add_library(${PROJECT_NAME} STATIC ${UNIFORM_SRC_FILES})
target_compile_definitions(${PROJECT_NAME} PUBLIC UNIFORM_LIBRARY)

# Compilation flags
target_compile_definitions(${PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:_DEBUG_>")
target_compile_definitions(${PROJECT_NAME} PUBLIC "$<$<CONFIG:RELEASE>:_RELEASE_>")

# GLFW connection
set(UNIFORM_GLFW_DIR "${UNIFORM_VENDOR_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")
add_subdirectory("${UNIFORM_GLFW_DIR}/")

target_link_libraries(${PROJECT_NAME} "glfw" ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE "${UNIFORM_GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# GLAD connection
set(UNIFORM_GLAD_DIR "${UNIFORM_VENDOR_DIR}/glad")
add_library(glad STATIC
    "${UNIFORM_GLAD_DIR}/src/glad.c"
    "${UNIFORM_GLAD_DIR}/include/glad/glad.h"
)
target_include_directories(glad PUBLIC "${UNIFORM_GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} glad ${CMAKE_DL_LIBS})

# Termcolor connection
set(UNIFORM_TERMCOLOR_DIR "${UNIFORM_VENDOR_DIR}/termcolor")
add_subdirectory("${UNIFORM_TERMCOLOR_DIR}/")
target_link_libraries(${PROJECT_NAME} termcolor)

# Imgui connection
set(UNIFORM_IMGUI_DIR "${UNIFORM_VENDOR_DIR}/imgui")
target_include_directories(${PROJECT_NAME} PRIVATE "${UNIFORM_IMGUI_DIR}/")
add_library(imgui STATIC
    "${UNIFORM_IMGUI_DIR}/imgui.h"
    "${UNIFORM_IMGUI_DIR}/imgui.cpp"
    "${UNIFORM_IMGUI_DIR}/imgui_demo.cpp"
    "${UNIFORM_IMGUI_DIR}/imgui_draw.cpp"
    "${UNIFORM_IMGUI_DIR}/imgui_internal.h"
    "${UNIFORM_IMGUI_DIR}/imgui_widgets.cpp"
    "${UNIFORM_IMGUI_DIR}/imstb_rectpack.h"
    "${UNIFORM_IMGUI_DIR}/imstb_textedit.h"
    "${UNIFORM_IMGUI_DIR}/imstb_truetype.h"
    "${UNIFORM_IMGUI_DIR}/examples/imgui_impl_glfw.h"
    "${UNIFORM_IMGUI_DIR}/examples/imgui_impl_glfw.cpp"
    "${UNIFORM_IMGUI_DIR}/examples/imgui_impl_opengl3.h"
    "${UNIFORM_IMGUI_DIR}/examples/imgui_impl_opengl3.cpp"
)
target_include_directories(imgui PUBLIC "${UNIFORM_IMGUI_DIR}/")
target_link_libraries(imgui PRIVATE glfw ${GLFW_LIBRARIES})
target_link_libraries(imgui PRIVATE glad ${CMAKE_DL_LIBS})
target_compile_definitions(imgui PRIVATE "IMGUI_IMPL_OPENGL_LOADER_GLAD")
target_link_libraries(${PROJECT_NAME} imgui)

# Threads connection
find_package(Threads)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

# Options
option(UNIFORM_BUILD_TESTS "Build the Uniform test programs" TRUE)

# Tests building
if (UNIFORM_BUILD_TESTS)
 add_subdirectory("${UNIFORM_TESTS_DIR}/events/")
 add_subdirectory("${UNIFORM_TESTS_DIR}/modules/")
 add_subdirectory("${UNIFORM_TESTS_DIR}/layers/")
 add_subdirectory("${UNIFORM_TESTS_DIR}/vector/")
 add_subdirectory("${UNIFORM_TESTS_DIR}/window/")
endif ()