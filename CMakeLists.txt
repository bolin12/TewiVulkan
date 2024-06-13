cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(NAME TewiVulkan)


project(${NAME} VERSION 1.0
                LANGUAGES CXX)


include_directories(thirdparty/glfw)
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

message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

message(STATUS "Find libs")

find_package(Vulkan)
message(STATUS "Vulkan found: ${Vulkan_FOUND}")
if(NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan not found")
endif()



find_package(glfw3)
message(STATUS "glfw3 found: ${glfw3_FOUND}")
if(NOT glfw3_FOUND)
    message(FATAL_ERROR "glfw3 not found")
endif()



find_package(glm)
message(STATUS "glm found: ${glm_FOUND}")
if(NOT glm_FOUND)
    message(FATAL_ERROR "glm not found")
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Compiler specific stuff
IF(MSVC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
ENDIF()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

add_subdirectory(src)


