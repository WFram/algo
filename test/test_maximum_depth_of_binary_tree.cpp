//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <maximum_depth_of_binary_tree.h>

TEST(maximum_depth_of_binary_tree, maximum_depth_of_binary_tree) {
  using Solution = maximum_depth_of_binary_tree::NormalSolution;
  {
    TreeNodePtr root = std::make_unique<TreeNode>(3);
    root->addChildren(std::make_unique<TreeNode>(9), std::make_unique<TreeNode>(20));
    root->right_->addChildren(std::make_unique<TreeNode>(15), std::make_unique<TreeNode>(7));
    Solution solution;
    int result = solution.maxDepth(std::move(root));
    ASSERT_EQ(result, 3);
  }
  {
    TreeNodePtr root = std::make_unique<TreeNode>(1);
    root->addChildren(nullptr, std::make_unique<TreeNode>(2));
    Solution solution;
    int result = solution.maxDepth(std::move(root));
    ASSERT_EQ(result, 2);
  }
}