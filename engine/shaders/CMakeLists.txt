function(compile_shader SHADERS TARGET_NAME SHADER_INCLUDE_FOLDER GENERATED_DIR GLSLANG_BIN)

    set(working_dir "${CMAKE_CURRENT_SOURCE_DIR}")
    # message(STATUS "working_dir: ${working_dir}")
    set(ALL_GENERATED_SPV_FILES "")

    foreach(SHADER ${SHADERS})
    # Prepare a header name and a global variable for this shader
        get_filename_component(SHADER_NAME ${SHADER} NAME)
        string(REPLACE "." "_" HEADER_NAME ${SHADER_NAME})
        string(TOUPPER ${HEADER_NAME} GLOBAL_SHADER_VAR)

        set(SPV_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_DIR}/spv/${SHADER_NAME}.spv")
        set(CPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_DIR}/cpp/${HEADER_NAME}.h")
        message(STATUS "Running command: ${GLSLANG_BIN} -I${SHADER_INCLUDE_FOLDER} -gVS -V100 -o ${SPV_FILE} ${SHADER}")
        add_custom_command(
            OUTPUT ${SPV_FILE}
            COMMAND ${CMAKE_COMMAND} -E echo "Running command: ${GLSLANG_BIN} -I${SHADER_INCLUDE_FOLDER} -gVS -V100 -o ${SPV_FILE} ${SHADER}"
            COMMAND ${GLSLANG_BIN} -I${SHADER_INCLUDE_FOLDER} -gVS -V100 -o ${SPV_FILE} ${SHADER}
            DEPENDS ${SHADER}
            WORKING_DIRECTORY "${working_dir}")

        list(APPEND ALL_GENERATED_SPV_FILES ${SPV_FILE})

    endforeach()

    add_custom_target(
        ${TARGET_NAME} ALL # tewili notes why bydefault this will not be added to the default build target
        DEPENDS ${ALL_GENERATED_SPV_FILES}
        SOURCES ${SHADERS}
        COMMENT "Shader SPIR-V Compilation Completed."
    )

endfunction()



set(TARGET_NAME ${SHADER_COMPILE_TARGET})
# message(STATUS "SHADER_COMPILE_TARGET : ${SHADER_COMPILE_TARGET}")

file(GLOB_RECURSE SHADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.vert"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.frag"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.comp"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.geom"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.tesc"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.tese"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.mesh"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.task"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.rgen"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.rchit"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.rmiss"
                                            "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.rcall")

SOURCE_GROUP("shaders" FILES ${SHADER_FILES})

set(SHADER_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(GENERATED_SHADER_FOLDER "generated")

if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER})
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER})
endif()

if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER}/spv)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER}/spv)
endif()


message(STATUS "Vulkan_GLSLANG_VALIDATOR_EXECUTABLE: ${Vulkan_GLSLANG_VALIDATOR_EXECUTABLE}")
compile_shader(
  "${SHADER_FILES}"
  "${TARGET_NAME}"
  "${SHADER_INCLUDE_FOLDER}" 
  "${GENERATED_SHADER_FOLDER}"
  "${glslangValidator_executable}")

# set_target_properties("${TARGET_NAME}" PROPERTIES FOLDER "Engine" )