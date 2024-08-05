
# Add shaders
#----------------------shader compile ------------------------------------------
set(SHADER_DIR_GLSL "${CMAKE_SOURCE_DIR}/shaders/glsl")
file(GLOB SHADERS_GLSL "${SHADER_DIR_GLSL}/*.vert" "${SHADER_DIR_GLSL}/*.frag" "${SHADER_DIR_GLSL}/*.comp" "${SHADER_DIR_GLSL}/*.geom" "${SHADER_DIR_GLSL}/*.tesc" "${SHADER_DIR_GLSL}/*.tese" "${SHADER_DIR_GLSL}/*.mesh" "${SHADER_DIR_GLSL}/*.task" "${SHADER_DIR_GLSL}/*.rgen" "${SHADER_DIR_GLSL}/*.rchit" "${SHADER_DIR_GLSL}/*.rmiss" "${SHADER_DIR_GLSL}/*.rcall" "${SHADER_DIR_GLSL}/*.rahit" "${SHADER_DIR_GLSL}/*.rint" "${SHADER_DIR_GLSL}/*.glsl")

source_group("Shaders\\GLSL" FILES ${SHADERS_GLSL})
message(STATUS "SHADERS_GLSL: ${SHADERS_GLSL}")


foreach(SHADER ${SHADERS_GLSL})
    get_filename_component(SHADER_NAME ${SHADER} NAME)
    set(SHADER_SPIRV "${SHADER_DIR_GLSL}/${SHADER_NAME}.spv")
    add_custom_command(
        OUTPUT ${SHADER_SPIRV}
        COMMAND ${Vulkan_GLSLC_EXECUTABLE} ${SHADER} -o ${SHADER_SPIRV}
        DEPENDS ${SHADER}
        COMMENT "Compiling ${SHADER_NAME}"
    )
    list(APPEND SPIRV_BINARY_FILES ${SHADER_SPIRV})
endforeach()


add_custom_target(
    Shaders ALL
    DEPENDS ${SPIRV_BINARY_FILES}
    COMMENT "Shader SPIR-V Compilation Completed."
)


#-------------------shader compile---------------------------------------------



# if(WIN32)

SET(SRC_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
# message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
# Main
file(GLOB_RECURSE SOURCE
    ${SRC_FOLDER}/core/*.cpp
    ${SRC_FOLDER}/core/*.h
)


SET(MAIN_CPP ${SRC_FOLDER}/main.cpp)
# message(STATUS "SOURCE: ${SOURCE}")
# message(STATUS "MAIN_CPP: ${MAIN_CPP}")


# if(EXISTS ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.h)
#     SET(MAIN_HEADER ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.h)
# ENDIF()

add_executable(main WIN32 ${MAIN_CPP} ${SOURCE} ${SHADERS_GLSL} )
# message(STATUS "VULKAN_LIBRARY: ${Vulkan_LIBRARY}")

target_link_libraries(main ${Vulkan_LIBRARY}  ${GLFW3_LIBRARY})
target_include_directories(main PRIVATE ${Vulkan_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS} ${STB_IMAGE_SOURCES} ${TINYOBJLOADER_SOURCES})


IF(MSVC)
    target_link_options(main PRIVATE "/SUBSYSTEM:CONSOLE")
ENDIF()


# file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}) # tewili notes influence file search path
# set_target_properties(${EXAMPLE_NAME} PROPERTIES LINK_FLAGS /DEBUG)

# if(RESOURCE_INSTALL_DIR)
#     install(TARGETS main DESTINATION ${CMAKE_INSTALL_BINDIR})
# endif()

