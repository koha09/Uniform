cmake_minimum_required(VERSION 3.12)

# Project configuration
project(Uniform VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

# Working directories
set(UNIFORM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(UNIFORM_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(UNIFORM_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")
set(UNIFORM_EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")

# Searching all source files
file(GLOB_RECURSE UNIFORM_SRC_FILES
    "${UNIFORM_SRC_DIR}/*.hpp"
    "${UNIFORM_SRC_DIR}/*.cpp"
)

# Search all dependencies files
file(GLOB_RECURSE UNIFORM_VENDOR_FILES
    "${UNIFORM_VENDOR_DIR}/*.hpp"
    "${UNIFORM_VENDOR_DIR}/*.h"
    "${UNIFORM_VENDOR_DIR}/*.cpp"
    "${UNIFORM_VENDOR_DIR}/*.c"
)

# Library setup
add_library(${PROJECT_NAME} STATIC ${UNIFORM_SRC_FILES})

# Including of headers
target_include_directories(${PROJECT_NAME} PUBLIC "${UNIFORM_SRC_DIR}/")
target_compile_definitions(${PROJECT_NAME} PUBLIC "UNIFORM_LIBRARY")

# Setting of special macro definitions
target_compile_definitions(${PROJECT_NAME} INTERFACE "UNIFORM_LIBRARY")
target_compile_definitions(${PROJECT_NAME} INTERFACE "$<$<CONFIG:DEBUG>:_DEBUG_>")
target_compile_definitions(${PROJECT_NAME} INTERFACE "$<$<CONFIG:RELEASE>:_RELEASE_>")

# GLFW
set(UNIFORM_GLFW_DIR "${UNIFORM_VENDOR_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")
add_subdirectory("${UNIFORM_GLFW_DIR}/")

target_link_libraries(${PROJECT_NAME} "glfw" ${GLFW_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} INTERFACE "GLFW_INCLUDE_NONE")
target_include_directories(${PROJECT_NAME} INTERFACE "${UNIFORM_GLFW_DIR}/include")

# GLAD
set(UNIFORM_GLAD_DIR "${UNIFORM_VENDOR_DIR}/glad")
add_library(glad STATIC
    "${UNIFORM_GLAD_DIR}/src/glad.c"
    "${UNIFORM_GLAD_DIR}/include/glad/glad.h"
)
target_include_directories(glad PUBLIC "${UNIFORM_GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} glad ${CMAKE_DL_LIBS})

# Termcolor
set(UNIFORM_TERMCOLOR_DIR "${UNIFORM_VENDOR_DIR}/termcolor")
add_subdirectory("${UNIFORM_TERMCOLOR_DIR}/")
target_link_libraries(${PROJECT_NAME} termcolor)

# ImGui
set(UNIFORM_IMGUI_DIR "${UNIFORM_VENDOR_DIR}/imgui")
target_include_directories(${PROJECT_NAME} INTERFACE "${UNIFORM_IMGUI_DIR}/")
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

# STB
set(UNIFORM_STB_DIR "${UNIFORM_VENDOR_DIR}/stb")
target_include_directories(${PROJECT_NAME} PRIVATE "${UNIFORM_STB_DIR}/")
target_compile_definitions(${PROJECT_NAME} PRIVATE "STB_IMAGE_IMPLEMENTATION")

option(UNIFORM_BUILD_TESTS "Build the Uniform test programs" TRUE)

if (UNIFORM_BUILD_TESTS)
 add_subdirectory("${UNIFORM_EXAMPLES_DIR}/texture/")
 add_subdirectory("${UNIFORM_EXAMPLES_DIR}/shader/")
endif ()