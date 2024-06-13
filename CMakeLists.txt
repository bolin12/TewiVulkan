cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(NAME TewiVulkan)


project(${NAME} VERSION 1.0
                LANGUAGES CXX)


include_directories(thirdparty/glfw/include)
include_directories(thirdparty/glm)
include_directories(thirdparty/stb)
include_directories(thirdparty/tinyobjloader)
include_directories(thirdparty/imgui)
include_directories(thirdparty/imgui/backends)
include_directories(thirdparty/glslang)
include_directories(thirdparty/vulkan-headers/include)


# get_property(dirs DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
# foreach(dir ${dirs})
#   message(STATUS "Include directory: ${dir}")
# endforeach()



message(STATUS "Find libs")

find_package(Vulkan)
message(STATUE "Vulkan found: ${Vulkan_FOUND}")
if(NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan not found")
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")


add_subdirectory(src)


