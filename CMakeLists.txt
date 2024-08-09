cmake_minimum_required(VERSION 3.19 FATAL_ERROR)


project(TewiEngine VERSION 1.0
                LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


# Compiler specific stuff
IF(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
ENDIF()


# Set preprocessor defines
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -D_USE_MATH_DEFINES")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")


set(TEWI_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(BINARY_ROOT_DIR ${CMAKE_SOURCE_DIR}/bin)



include(cmake/print_all_variables.cmake)



add_subdirectory(engine)
