file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")


SET(MAIN_CPP main.cpp)


add_executable(main WIN32 ${MAIN_CPP} ${HEADER_FILES} ${SOURCE_FILES} )
# message(STATUS "VULKAN_LIBRARY: ${Vulkan_LIBRARY}")

target_link_libraries(main ${Vulkan_LIBRARY}  ${GLFW3_LIBRARY})
target_include_directories(main PRIVATE ${SRC_FOLDER}/core ${Vulkan_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS} ${STB_IMAGE_SOURCES} ${TINYOBJLOADER_SOURCES})
# tewili todo: fix structure of this repo

IF(MSVC)
    target_link_options(main PRIVATE "/SUBSYSTEM:CONSOLE")
ENDIF()


# file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}) # tewili notes: influence file search path
# set_target_properties(${EXAMPLE_NAME} PROPERTIES LINK_FLAGS /DEBUG)

# if(RESOURCE_INSTALL_DIR)
#     install(TARGETS main DESTINATION ${CMAKE_INSTALL_BINDIR})
# endif()

message(STATUS "${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/data" "${BINARY_ROOT_DIR}"")

set(POST_BUILD_COMMANDS
  COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/${ASSET_DIR}" "${BINARY_ROOT_DIR}/${ASSET_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:main>/" "${BINARY_ROOT_DIR}"
)

add_custom_command(TARGET main ${POST_BUILD_COMMANDS})