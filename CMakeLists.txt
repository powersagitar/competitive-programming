cmake_minimum_required(VERSION 3.31)

project(competitive-programming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(canadian-computing-competition)
add_subdirectory(dmoj)
