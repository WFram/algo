cmake_minimum_required(VERSION 3.21)
project(wf_leetcode C CXX)

# TODO: 1) create a shared library with solutions
#       2) create headers for each solution
#       3) include the headers
#       4) link the lib to tests

set(CMAKE_CXX_STANDARD 20)

include(dependencies.cmake)

set(SOLUTIONS_SRC
        # TODO: use a flag
        src/solutions/src/remove_duplicates_from_sorted_array.cpp
        )

# TODO: use a flag
include_directories(src/solutions/include)
add_library(solutions ${SOLUTIONS_SRC})

enable_testing()
include(cmake/addTest.cmake)
add_subdirectory(test)
