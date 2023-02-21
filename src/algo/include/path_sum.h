//
// Created by wfram on 2/18/23.
//

#ifndef WF_LEETCODE_PATH_SUM_H
#define WF_LEETCODE_PATH_SUM_H

#include <functional>
#include <iostream>
#include <memory>

// https://leetcode.com/problems/path-sum/
namespace path_sum {

struct TreeNode {
  int val;
  // TODO: do we need make them shared? For this case seems to be more than enough
  // TODO: do we need to move?
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right)
      : val(val), left(std::move(left)), right(std::move(right)) {}
};

using TreeNodePtr = std::shared_ptr<TreeNode>;

void addTreeNode(TreeNodePtr root, TreeNodePtr left, TreeNodePtr right);

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

#endif  // WF_LEETCODE_PATH_SUM_H
