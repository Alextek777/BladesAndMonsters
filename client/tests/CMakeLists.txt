cmake_minimum_required(VERSION 3.10)
project(tests)

# Add GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test files
add_executable(runTests main.cpp)

# Link test executable against gtest and gtest_main
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Register the test with CTest
add_test(NAME HelloTest COMMAND runTests)