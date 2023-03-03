cmake_minimum_required(VERSION 3.21)
project(wf_algo C CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(dependencies.cmake)

set(SOLUTIONS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/algo/src)

set(SOLUTIONS_SRC_FILES
        ${SOLUTIONS_SRC_DIR}/remove_duplicates_from_sorted_array.cpp
        ${SOLUTIONS_SRC_DIR}/palindrome_number.cpp
        ${SOLUTIONS_SRC_DIR}/path_sum.cpp
        ${SOLUTIONS_SRC_DIR}/validate_binary_search_tree.cpp
        ${SOLUTIONS_SRC_DIR}/maximum_depth_of_binary_tree.cpp
        ${SOLUTIONS_SRC_DIR}/symmetric_tree.cpp
        )

#[[ CMAKE_CURRENT_SOURCE_DIR is /home/wfram/wf_leetcode  ]]
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/algo/include/data_structures)
add_library(algo ${SOLUTIONS_SRC_FILES})
target_include_directories(algo PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/algo/include>)

enable_testing()
include(cmake/addTest.cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
