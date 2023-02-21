#[[ CMAKE_SOURCE_DIR is /home/wfram/wf_leetcode ]]
include_directories(${CMAKE_SOURCE_DIR}/src/algo/include)
project_add_test(test_remove_duplicates_from_sorted_array test_remove_duplicates_from_sorted_array.cpp algo)
project_add_test(test_palindrome_number test_palindrome_number.cpp algo)
project_add_test(test_path_sum test_path_sum.cpp algo)

