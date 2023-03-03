//
// Created by wfram on 2/17/23.
//

#ifndef WF_ALGO_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define WF_ALGO_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
namespace remove_duplicates_from_sorted_array {

class Solution {
 public:
  Solution() = default;

  virtual int removeDuplicates(std::vector<int> &nums) = 0;
};

class NormalSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override;
};

// Sample solution
class FastSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override;
};

// Sample solution
class MemoryEfficientSolution : public Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) override;
};

}  // namespace remove_duplicates_from_sorted_array

#endif  // WF_ALGO_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
