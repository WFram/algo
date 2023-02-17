//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <remove_duplicates_from_sorted_array.h>

template <class Solution>
void pass(std::vector<int> &nums, const std::vector<int> &expected_nums) {
  Solution solution;
  int k = solution.removeDuplicates(nums);
  std::cout << "Length: " << k << std::endl;
  std::cout << "Length: " << expected_nums.size() << std::endl;
  assert(k == expected_nums.size());
  for (int i = 0; i < k; i++) {
    assert(nums[i] == expected_nums[i]);
  }
}

int main() {
  using Solution = remove_duplicates_from_sorted_array::NormalSolution;
  std::vector<int> nums = {1, 1, 2};
  std::vector<int> expected_nums = {1, 2};
  pass<Solution>(nums, expected_nums);
  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  expected_nums = {0, 1, 2, 3, 4};
  std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();
  pass<Solution>(nums, expected_nums);
  std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
  std::cout << "Passed!" << std::endl;
  std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()
            << " us" << std::endl;
  return 0;
}