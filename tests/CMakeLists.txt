cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "LLL-Tests")

project(${PROJECT_NAME} C CXX)

set(CMAKE_C_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(../sources)

enable_testing()

# Build the library
add_executable(Tests_LLL
        bitmanip/test_bitmanip.cpp)

target_link_libraries(
        Tests_LLL
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests_LLL)