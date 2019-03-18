project(opencv_test)
cmake_minimum_required(VERSION 3.1)

# Create a results dir in project root where we will put the results of the
# build
set(RESULTS_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/results)
file(MAKE_DIRECTORY ${RESULTS_OUTPUT_DIRECTORY})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RESULTS_OUTPUT_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RESULTS_OUTPUT_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RESULTS_OUTPUT_DIRECTORY}/bin)

find_package(OpenCV 3 REQUIRED)
find_package(Qt5 REQUIRED
             COMPONENTS Core
                        Widgets
                        Test
                        OpenGL
                        Concurrent)

add_subdirectory("src")
