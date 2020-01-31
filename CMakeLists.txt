cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR}/include)
#Enable debug symbols
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose debug or release" FORCE)
    set(CMAKE_CXX_FLAGS "-Wall -Wconversion -ggdb")
endif()

project(game)

#Add the files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_SOURCE_DIR}/src/CGJ/Tests/*.cpp)
set(LIB_SOURCES ${SOURCES})
add_executable(game ${SOURCES})
list(REMOVE_ITEM LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/CGJ/main.cpp)
list(REMOVE_ITEM LIB_SOURCES ${TEST_SOURCES})
# set the output directory for SFML libraries
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
add_library(cgj SHARED ${LIB_SOURCES})

#OPENGL
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)
set(GL_LIBRARY GL GLEW X11)

#Threads
find_package(Threads)

target_link_libraries(game Threads::Threads ${EXECUTABLE_NAME} ${GL_LIBRARY} -lgtest -lgtest_main)
#target_link_libraries(libcgj libcgj.so)
