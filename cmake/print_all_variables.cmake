
# print_all_variables.cmake
set(OUTPUT_FILE "${CMAKE_SOURCE_DIR}/cmake_variables.txt")
file(WRITE ${OUTPUT_FILE} "---- CMake Variables ----\n")

get_cmake_property(_variableNames VARIABLES)
list(SORT _variableNames)
foreach (_variableName ${_variableNames})
    file(APPEND ${OUTPUT_FILE} "${_variableName}=${${_variableName}}\n")
endforeach()
file(APPEND ${OUTPUT_FILE} "---- End of CMake Variables ----\n")
