cmake_minimum_required(VERSION 3.21)
project(wf_algo C CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(dependencies.cmake)

#[[ /home/wfram/wf_leetcode/src/algo/src ]]
set(SOLUTIONS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/algo/src)

#[[ Check, we can successfully open the files ]]
set(SOLUTIONS_SRC_FILES
        ${SOLUTIONS_SRC_DIR}/remove_duplicates_from_sorted_array.cpp
        ${SOLUTIONS_SRC_DIR}/palindrome_number.cpp
        ${SOLUTIONS_SRC_DIR}/path_sum.cpp
        )

#[[ CMAKE_CURRENT_SOURCE_DIR is /home/wfram/wf_leetcode  ]]
add_library(algo ${SOLUTIONS_SRC_FILES})
target_include_directories(algo PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/algo/include>)

add_executable(validate_binary_search_tree src/validate_binary_search_tree.cpp)
add_executable(maximum_depth_of_binary_tree src/maximum_depth_of_binary_tree.cpp)

enable_testing()
include(cmake/addTest.cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
