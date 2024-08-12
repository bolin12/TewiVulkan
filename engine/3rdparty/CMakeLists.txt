set(CMAKE_THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/3rdparty)


if(NOT TARGET imgui)
    include(imgui.cmake)
    set_target_properties(imgui PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/imgui)
endif()

if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/glfw)
    set_target_properties(update_mappings PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/glfw)
endif()



 if(NOT TARGET spdlog)
     option(SPDLOG_BUILD_EXAMPLE "" OFF)
     option(SPDLOG_INSTALL "" OFF)
     add_subdirectory(spdlog)
     set_target_properties(spdlog PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/spdlog)
 endif()

if(NOT TARGET stb)
    include(stb.cmake)
    set_target_properties(stb PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/stb)
endif()

if(NOT TARGET tinyobjloader)
    add_subdirectory(tinyobjloader)
    set_target_properties(tinyobjloader PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/tinyobjloader)
    set_target_properties(uninstall PROPERTIES FOLDER ${CMAKE_THIRD_PARTY_DIR}/tinyobjloader)
endif()


if(NOT TARGET glm)
    add_subdirectory(glm)
endif()