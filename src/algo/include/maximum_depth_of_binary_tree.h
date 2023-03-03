//
// Created by wfram on 2/17/23.
//

#ifndef WF_ALGO_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define WF_ALGO_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include <functional>
#include <iostream>

#include <tree_node.h>

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
namespace maximum_depth_of_binary_tree {

class Solution {
 public:
  virtual int maxDepth(TreeNodePtr root) = 0;
};

class NormalSolution : public Solution {
 public:
  int maxDepth(TreeNodePtr root) override;
};

class MemoryEfficientSolution : public Solution {
 public:
  int maxDepth(TreeNodePtr root) override;
};

}  // namespace maximum_depth_of_binary_tree

#endif  // WF_ALGO_MAXIMUM_DEPTH_OF_BINARY_TREE_H
