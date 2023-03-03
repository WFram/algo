//
// Created by wfram on 2/18/23.
//

#ifndef WF_ALGO_PATH_SUM_H
#define WF_ALGO_PATH_SUM_H

#include <functional>
#include <iostream>
#include <memory>

#include <tree_node.h>

// https://leetcode.com/problems/path-sum/
namespace path_sum {

class Solution {
 public:
  virtual bool hasPathSum(TreeNodePtr root, int targetSum) = 0;
};

class NormalSolution : public Solution {
 public:
  void calculateSum(TreeNodePtr root, int sum);

  bool hasPathSum(TreeNodePtr root, int targetSum) override;

 private:
  std::vector<int> sums_;
};

class FastSolution : public Solution {
 public:
  bool hasPathSum(TreeNodePtr root, int targetSum);
};

class MemoryEfficientSolution : public Solution {
 public:
  bool hasPathSum(TreeNodePtr root, int targetSum, int sumSoFar = 0);
};

}  // namespace path_sum

#endif  // WF_ALGO_PATH_SUM_H
