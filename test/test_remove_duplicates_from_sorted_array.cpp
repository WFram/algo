//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <remove_duplicates_from_sorted_array.h>

TEST(test_remove_duplicates_from_sorted_array, test_remove_duplicates_from_sorted_array) {
  using Solution = remove_duplicates_from_sorted_array::NormalSolution;
  std::vector<int> nums = {1, 1, 2};
  std::vector<int> expected_nums = {1, 2};
  Solution solution;
  int k = solution.removeDuplicates(nums);
  ASSERT_EQ(k, expected_nums.size());
  for (int i = 0; i < k; i++) {
    ASSERT_EQ(nums[i], expected_nums[i]);
  }
  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  expected_nums = {0, 1, 2, 3, 4};
  k = solution.removeDuplicates(nums);
  ASSERT_EQ(k, expected_nums.size());
  for (int i = 0; i < k; i++) {
    ASSERT_EQ(nums[i], expected_nums[i]);
  }
}
