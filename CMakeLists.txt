cmake_minimum_required(VERSION 3.10)

project(hagrid)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(hagrid src/main.cpp src/glad.c)

if(APPLE)
    find_library(LIBRARY_COCOA Cocoa)
    find_library(LIBRARY_OPENGL OpenGL)
    find_library(LIBRARY_IOKIT IOKit)

    target_link_libraries(hagrid ${LIBRARY_COCOA} ${LIBRARY_OPENGL} ${LIBRARY_IOKIT} ${CMAKE_SOURCE_DIR}/lib/libglfw3.a)
endif()

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
