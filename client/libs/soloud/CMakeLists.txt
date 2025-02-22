# libs/soloud/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(soloud LANGUAGES CXX)

add_definitions(-DWITH_MINIAUDIO)

# Include SoLoud headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include stb_vorbis headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../stb)

# Gather all SoLoud source files
file(GLOB_RECURSE SOLOUD_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

# Create the SoLoud library
add_library(soloud STATIC ${SOLOUD_SRC_FILES} ${STB_VORBIS_SRC_FILES})

# Set compiler flags (optional)
target_compile_options(soloud PRIVATE -Wall -Wextra -O3)

install(TARGETS soloud DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)