file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")


set(MAIN_CPP main.cpp)


add_executable(main WIN32 ${MAIN_CPP} ${HEADER_FILES} ${SOURCE_FILES} )


target_link_libraries(main ${Vulkan_LIBRARY}  ${GLFW3_LIBRARY})
target_include_directories(main PRIVATE ${SRC_FOLDER}/core ${Vulkan_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS} ${STB_IMAGE_SOURCES} ${TINYOBJLOADER_SOURCES})
# tewili todo: fix structure of this repo

IF(MSVC)
    target_link_options(main PRIVATE "/SUBSYSTEM:CONSOLE")
ENDIF()


set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}) # tewili notes: influence file search path



set(ASSET_DIR "/data")
set(POST_BUILD_COMMANDS
  COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/${ASSET_DIR}" "${BINARY_ROOT_DIR}/${ASSET_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:main>/" "${BINARY_ROOT_DIR}"
)

add_custom_command(TARGET main ${POST_BUILD_COMMANDS})