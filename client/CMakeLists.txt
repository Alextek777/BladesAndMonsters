cmake_minimum_required(VERSION 3.16)
project(BladesAndMonsters VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

file(COPY content/sprites DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY content/rpgdata DESTINATION ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/libs/src)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} -lpng -lGL -lX11)

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/content $<TARGET_FILE_DIR:${PROJECT_NAME}>/content
# )