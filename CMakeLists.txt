cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

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

add_subdirectory(src)
add_subdirectory(shaders)



include(cmake/print_all_variables.cmake)




set(POST_BUILD_COMMANDS
  COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resource" "${BINARY_ROOT_DIR}/resource"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/" "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy "${ENGINE_ROOT_DIR}/${DEPLOY_CONFIG_DIR}/${TARGET_NAME}.ini" "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy "${ENGINE_ROOT_DIR}/${DEVELOP_CONFIG_DIR}/${TARGET_NAME}.ini" "$<TARGET_FILE_DIR:${TARGET_NAME}>/"
  COMMAND ${CMAKE_COMMAND} -E remove_directory "${BINARY_ROOT_DIR}/${ENGINE_ASSET_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ENGINE_ROOT_DIR}/${ENGINE_ASSET_DIR}" "${BINARY_ROOT_DIR}/${ENGINE_ASSET_DIR}"
)


