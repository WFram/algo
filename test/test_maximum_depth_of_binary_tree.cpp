//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <maximum_depth_of_binary_tree.h>

template <class Solution>
void pass(maximum_depth_of_binary_tree::TreeNode *root) {
  Solution solution;
  int result = solution.maxDepth(root);
  std::cout << "Max Depth: " << result << std::endl;
}

int main() {
  using Solution = maximum_depth_of_binary_tree::NormalSolution;
  {
    maximum_depth_of_binary_tree::TreeNode *left_2 = new maximum_depth_of_binary_tree::TreeNode(15);
    maximum_depth_of_binary_tree::TreeNode *right_2 = new maximum_depth_of_binary_tree::TreeNode(7);
    maximum_depth_of_binary_tree::TreeNode *left_1 = new maximum_depth_of_binary_tree::TreeNode(9);
    maximum_depth_of_binary_tree::TreeNode *right_1 = new maximum_depth_of_binary_tree::TreeNode(20, left_2, right_2);
    maximum_depth_of_binary_tree::TreeNode *root = new maximum_depth_of_binary_tree::TreeNode(3, left_1, right_1);
    pass<Solution>(root);
  }
  {
    maximum_depth_of_binary_tree::TreeNode *right = new maximum_depth_of_binary_tree::TreeNode(2);
    maximum_depth_of_binary_tree::TreeNode *root = new maximum_depth_of_binary_tree::TreeNode(1, nullptr, right);
    pass<Solution>(root);
  }
}