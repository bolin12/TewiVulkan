# Copyright (c) 2016-2024, Sascha Willems
# SPDX-License-Identifier: MIT

# Function for building single example
function(buildExample EXAMPLE_NAME)
	SET(EXAMPLE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_NAME})
	message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")
	# Main
	file(GLOB SOURCE *.cpp ${BASE_HEADERS} ${EXAMPLE_FOLDER}/*.cpp)
	SET(MAIN_CPP ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.cpp)
    message(STATUS "SOURCE: ${SOURCE}")
    message(STATUS "MAIN_CPP: ${MAIN_CPP}")


	if(EXISTS ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.h)
		SET(MAIN_HEADER ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.h)
	ENDIF()

	# wayland requires additional source files
	IF(USE_WAYLAND_WSI)
		SET(SOURCE ${SOURCE} ${CMAKE_BINARY_DIR}/xdg-shell-client-protocol.h ${CMAKE_BINARY_DIR}/xdg-shell-protocol.c)
	ENDIF()
	# Add shaders
	set(SHADER_DIR_GLSL "../shaders/glsl/${EXAMPLE_NAME}")
	file(GLOB SHADERS_GLSL "${SHADER_DIR_GLSL}/*.vert" "${SHADER_DIR_GLSL}/*.frag" "${SHADER_DIR_GLSL}/*.comp" "${SHADER_DIR_GLSL}/*.geom" "${SHADER_DIR_GLSL}/*.tesc" "${SHADER_DIR_GLSL}/*.tese" "${SHADER_DIR_GLSL}/*.mesh" "${SHADER_DIR_GLSL}/*.task" "${SHADER_DIR_GLSL}/*.rgen" "${SHADER_DIR_GLSL}/*.rchit" "${SHADER_DIR_GLSL}/*.rmiss" "${SHADER_DIR_GLSL}/*.rcall" "${SHADER_DIR_GLSL}/*.rahit" "${SHADER_DIR_GLSL}/*.rint" "${SHADER_DIR_GLSL}/*.glsl")
	set(SHADER_DIR_HLSL "../shaders/hlsl/${EXAMPLE_NAME}")
	file(GLOB SHADERS_HLSL "${SHADER_DIR_HLSL}/*.vert" "${SHADER_DIR_HLSL}/*.frag" "${SHADER_DIR_HLSL}/*.comp" "${SHADER_DIR_HLSL}/*.geom" "${SHADER_DIR_HLSL}/*.tesc" "${SHADER_DIR_HLSL}/*.tese" "${SHADER_DIR_HLSL}/*.mesh" "${SHADER_DIR_HLSL}/*.task" "${SHADER_DIR_HLSL}/*.rgen" "${SHADER_DIR_HLSL}/*.rchit" "${SHADER_DIR_HLSL}/*.rmiss" "${SHADER_DIR_HLSL}/*.rcall" "${SHADER_DIR_HLSL}/*.rahit" "${SHADER_DIR_HLSL}/*.rint")
	source_group("Shaders\\GLSL" FILES ${SHADERS_GLSL})
	source_group("Shaders\\HLSL" FILES ${SHADERS_HLSL})
	# Add optional readme / tutorial
	file(GLOB README_FILES "${EXAMPLE_FOLDER}/*.md")
	# if(WIN32)

    add_executable(${EXAMPLE_NAME} WIN32 ${MAIN_CPP} ${SOURCE} ${MAIN_HEADER} ${SHADERS_GLSL} ${SHADERS_HLSL} ${README_FILES})
    message(STATUS "VULKAN_LIBRARY: ${Vulkan_LIBRARY}")
    target_link_libraries(${EXAMPLE_NAME} ${Vulkan_LIBRARY})
    target_link_libraries(${EXAMPLE_NAME} ${GLFW3_LIBRARY} )


    IF(MSVC)
        target_link_options(${EXAMPLE_NAME} PRIVATE "/SUBSYSTEM:CONSOLE")
    ENDIF()


	file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
	set_target_properties(${EXAMPLE_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
	# set_target_properties(${EXAMPLE_NAME} PROPERTIES LINK_FLAGS /DEBUG)

	if(RESOURCE_INSTALL_DIR)
		install(TARGETS ${EXAMPLE_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
	endif()
endfunction(buildExample)




# Build all examples
function(buildExamples)
	foreach(EXAMPLE ${EXAMPLES})
		buildExample(${EXAMPLE})
	endforeach(EXAMPLE)
endfunction(buildExamples)

set(EXAMPLES
	demo
)

buildExamples()