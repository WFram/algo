#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
 public:
  virtual int removeDuplicates(std::vector<int> &nums) = 0;
};

class NormalSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return static_cast<int>(nums.size());
  }
};

// Sample solution
class FastSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override {
    int j{1};
    for (int i = 1; i < nums.size(); i++)
      if (nums[i] != nums[i - 1]) nums[j++] = nums[i];
    return j;
  }
};

// Sample solution
class MemoryEfficientSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override {
    int size_nums = static_cast<int>(nums.size());
    if (size_nums == 0 or size_nums == 1) return size_nums;

    int last_num = nums[0];
    for (int i = 1; i < size_nums; ++i) {
      if (last_num == nums[i]) {
        nums.erase(nums.begin() + i);
        --size_nums;
        --i;
      } else
        last_num = nums[i];
    }

    return size_nums;
  }
};

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
  using Solution = NormalSolution;
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
