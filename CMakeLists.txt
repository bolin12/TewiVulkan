cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(NAME TewiVulkan)

project(${NAME} LANGUAGE CXX)

include_directories(third_party/glfw/include)
include_directories(third_party/glm)
include_directories(third_party/stb)

add_subdirectory(src)

add_executable(${NAME} main.cpp)

target_link_libraries(${NAME} glfw)

















