set(TARGET_NAME runtime)


file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")


source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${SOURCE_FILES})



add_library(${TARGET_NAME} ${HEADER_FILES} ${SOURCE_FILES} )
set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)


target_link_libraries(${TARGET_NAME} PRIVATE tinyobjloader stb)
target_link_libraries(${TARGET_NAME} PUBLIC glfw)
target_link_libraries(${TARGET_NAME} PUBLIC imgui)
target_link_libraries(${TARGET_NAME} PUBLIC ${vulkan_lib})
target_link_libraries(${TARGET_NAME} PUBLIC glm) # tewi wierd why commiting this line would cause include file not found error?


target_include_directories(
  ${TARGET_NAME}
  PUBLIC $<BUILD_INTERFACE:${vulkan_include}>)

add_dependencies(${TARGET_NAME} ${SHADER_COMPILE_TARGET})
target_include_directories(
  ${TARGET_NAME}
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/shaders/generated/spv>)


target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)

message(STATUS "${CMAKE_THIRD_PARTY_DIR}/glm")
target_include_directories(
    ${TARGET_NAME} 
    PUBLIC ${CMAKE_THIRD_PARTY_DIR}/glm
)# for temp resolution










