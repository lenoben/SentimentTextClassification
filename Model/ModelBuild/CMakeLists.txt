cmake_minimum_required(VERSION 3.0.0)
project(modelBuild VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files with src/main.cpp
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Build executable
add_executable(modelBuild ${SOURCES})

# Link libraries
target_link_libraries(modelBuild PRIVATE -larmadillo -lz -lmlpack -lz -fopenmp)

# Set compilation flags
target_compile_options(modelBuild PRIVATE -Wconversion -fpermissive)

# Set output directory
set_target_properties(modelBuild PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out
)
