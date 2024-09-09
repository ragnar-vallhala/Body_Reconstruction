cmake_minimum_required(VERSION 3.10)

project(Body_Reconstruction VERSION 1.0)

find_package(OpenCV REQUIRED)
include_directories("include/")

file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "tests/*.cpp")

add_executable(recon ${TESTS} ${SOURCES})

target_link_libraries(recon ${OpenCV_LIBS})

target_include_directories(recon PRIVATE ${OpenCV_INCLUDE_DIRS})

