project(opencv_test)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV 3 REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Test OpenGL Concurrent REQUIRED)

add_subdirectory("src")