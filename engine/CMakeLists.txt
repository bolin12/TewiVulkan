
set(ENGINE_ROOT_DIR "${TEWI_ROOT_DIR}/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")



set(vulkan_include ${THIRD_PARTY_DIR}/VulkanSDK/include)


set(vulkan_lib ${THIRD_PARTY_DIR}/VulkanSDK/lib/vulkan-1.lib)
set(glslangValidator_executable ${THIRD_PARTY_DIR}/VulkanSDK/bin/glslangValidator.exe)
add_compile_definitions("PICCOLO_VK_LAYER_PATH=${THIRD_PARTY_DIR}/VulkanSDK/bin")


message(STATUS "glslangValidator_executable :${glslangValidator_executable}")



set(SHADER_COMPILE_TARGET shadercompile)



add_subdirectory(shaders)

add_subdirectory(3rdparty)

add_subdirectory(source/editor)

add_subdirectory(source/runtime)




