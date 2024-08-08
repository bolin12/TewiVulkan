cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

set(NAME TewiVulkan)


project(${NAME} VERSION 1.0
                LANGUAGES CXX)


set(CMAKE_THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/thirdparty)


set(STB_IMAGE_SOURCES ${CMAKE_THIRD_PARTY_DIR}/stb)
set(TINYOBJLOADER_SOURCES ${CMAKE_THIRD_PARTY_DIR}/tinyobjloader)
set(IMGUI_SOURCES ${CMAKE_THIRD_PARTY_DIR}/imgui)
set(GLM_SOURCES ${CMAKE_THIRD_PARTY_DIR}/glm)


# get_property(dirs DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
# foreach(dir ${dirs})
#   message(STATUS "Include directory: ${dir}")
# endforeach()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

# message(STATUS "CMAKE_FIND_PACKAGE_REDIRECTS_DIR: ${CMAKE_FIND_PACKAGE_REDIRECTS_DIR}")

message(STATUS "----------Finding libs--------------")

find_package(Vulkan REQUIRED)
message(STATUS "Vulkan found: ${Vulkan_FOUND}")


find_package(GLFW3 REQUIRED)
message(STATUS "GLFW3 found: ${GLFW3_FOUND}")


find_package(GLM REQUIRED)
message(STATUS "GLM found: ${GLM_FOUND}")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Compiler specific stuff
IF(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
ENDIF()


# Set preprocessor defines
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -D_USE_MATH_DEFINES")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")


set(SHADER_COMPILE_TARGET ShaderCompile)

set(BINARY_ROOT_DIR ${CMAKE_SOURCE_DIR}/bin)
set(ASSET_DIR "/data")





include(cmake/print_all_variables.cmake)






add_subdirectory(src)
add_subdirectory(shaders)
