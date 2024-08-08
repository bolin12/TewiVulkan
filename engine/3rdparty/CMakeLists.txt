set(CMAKE_THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/3rdparty)


if(NOT TARGET imgui)
    include(imgui.cmake)
    set_target_properties(imgui PROPERTIES FOLDER ${third_party_folder}/imgui)
endif()

if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER ${third_party_folder}/glfw)
    set_target_properties(update_mappings PROPERTIES FOLDER ${third_party_folder}/glfw)
endif()

if(NOT TARGET spdlog)
    option(SPDLOG_BUILD_EXAMPLE "" OFF)
    option(SPDLOG_INSTALL "" OFF)
    add_subdirectory(spdlog)
    set_target_properties(spdlog PROPERTIES FOLDER ${third_party_folder}/spdlog)
endif()

if(NOT TARGET stb)
    include(stb.cmake)
    set_target_properties(stb PROPERTIES FOLDER ${third_party_folder}/stb)
endif()

if(NOT TARGET tinyobjloader)
    add_subdirectory(tinyobjloader)
    set_target_properties(tinyobjloader PROPERTIES FOLDER ${third_party_folder}/tinyobjloader)
    set_target_properties(uninstall PROPERTIES FOLDER ${third_party_folder}/tinyobjloader)
endif()



set(STB_IMAGE_SOURCES ${CMAKE_THIRD_PARTY_DIR}/stb)
set(TINYOBJLOADER_SOURCES ${CMAKE_THIRD_PARTY_DIR}/tinyobjloader)
set(IMGUI_SOURCES ${CMAKE_THIRD_PARTY_DIR}/imgui)
set(GLM_SOURCES ${CMAKE_THIRD_PARTY_DIR}/glm)


find_package(Vulkan REQUIRED)
message(STATUS "Vulkan found: ${Vulkan_FOUND}")


find_package(GLFW3 REQUIRED)
message(STATUS "GLFW3 found: ${GLFW3_FOUND}")


find_package(GLM REQUIRED)
message(STATUS "GLM found: ${GLM_FOUND}")
