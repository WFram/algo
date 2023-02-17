//
// Created by wfram on 2/17/23.
//

#ifndef WF_LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define WF_LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include <functional>
#include <iostream>

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
namespace maximum_depth_of_binary_tree {
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  virtual int maxDepth(TreeNode *root) = 0;
};

class NormalSolution : public Solution {
 public:
  virtual int maxDepth(TreeNode *root) override;

 private:
  unsigned char counter = 1;
};
}  // namespace maximum_depth_of_binary_tree

#endif  // WF_LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
