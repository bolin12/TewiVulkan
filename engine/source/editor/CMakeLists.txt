set(TARGET_NAME editor)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES})


target_link_libraries(${TARGET_NAME} runtime)




set(ASSET_DIR "/data")
set(POST_BUILD_COMMANDS
  COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ENGINE_ROOT_DIR}/${ASSET_DIR}" "${BINARY_ROOT_DIR}/${ASSET_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/" "${BINARY_ROOT_DIR}"
)

add_custom_command(TARGET ${TARGET_NAME} ${POST_BUILD_COMMANDS})




set_target_properties(${TARGET_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}) # tewili notes: influence file search path




IF(MSVC)
    target_link_options(${TARGET_NAME} PRIVATE "/SUBSYSTEM:CONSOLE")
ENDIF()


