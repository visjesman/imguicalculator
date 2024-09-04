cmake_minimum_required(VERSION 3.10)

# Set the policy to use GLVND by default
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

project(QTtest)

set(CMAKE_CXX_STANDARD 17)

# Add the main executable
add_executable(QTtest src/main.cpp)

# Find and link GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(QTtest PRIVATE glfw)

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(QTtest PRIVATE OpenGL::GL)

# Find and link GLEW
find_package(GLEW REQUIRED)
target_link_libraries(QTtest PRIVATE GLEW::GLEW)

# Include ImGui files
add_library(imgui
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_tables.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_glfw.cpp
        src/main.cpp
        src/main.cpp
)

# Include directories for ImGui and other dependencies
target_include_directories(imgui PRIVATE
        ${CMAKE_SOURCE_DIR}/imgui
        ${CMAKE_SOURCE_DIR}/imgui/backends
)

target_include_directories(QTtest PRIVATE
        ${CMAKE_SOURCE_DIR}/imgui
        ${CMAKE_SOURCE_DIR}/imgui/backends
        ${GLEW_INCLUDE_DIRS}  # GLEW include directory
        ${GLFW_INCLUDE_DIRS}  # GLFW include directory
        /usr/include/GL  # OpenGL headers path (adjust if necessary)
)

# Link ImGui
target_link_libraries(QTtest PRIVATE imgui)
