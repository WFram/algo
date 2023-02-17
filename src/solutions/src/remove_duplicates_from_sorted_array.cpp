#include "remove_duplicates_from_sorted_array.h"

int remove_duplicates_from_sorted_array::NormalSolution::removeDuplicates(std::vector<int> &nums) {
  nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
  return static_cast<int>(nums.size());
}

// Sample solution
int remove_duplicates_from_sorted_array::FastSolution::removeDuplicates(std::vector<int> &nums) {
  int j{1};
  for (int i = 1; i < nums.size(); i++)
    if (nums[i] != nums[i - 1]) nums[j++] = nums[i];
  return j;
}

// Sample solution
int remove_duplicates_from_sorted_array::MemoryEfficientSolution::removeDuplicates(std::vector<int> &nums) {
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