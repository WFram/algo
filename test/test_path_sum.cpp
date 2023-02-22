//
// Created by wfram on 2/18/23.
//

#include <gtest/gtest.h>

#include <path_sum.h>

TEST(path_sum, path_sum) {
  using Solution = path_sum::NormalSolution;
  // TODO: solve how to organize better
  {
    // TODO: solve, we did smth wrong
    Solution solution;
    int targetSum = 22;
    TreeNodePtr root = std::make_unique<TreeNode>(5);
    root->addChildren(std::make_unique<TreeNode>(4), std::make_unique<TreeNode>(8));
    root->left_->addChildren(std::make_unique<TreeNode>(11), nullptr);
    root->right_->addChildren(std::make_unique<TreeNode>(13), std::make_unique<TreeNode>(4));
    root->left_->left_->addChildren(std::make_unique<TreeNode>(7), std::make_unique<TreeNode>(2));
    root->right_->right_->addChildren(nullptr, std::make_unique<TreeNode>(1));
    bool has_path_sum = solution.hasPathSum(std::move(root), targetSum);
    ASSERT_EQ(has_path_sum, true);
  }
  {
    Solution solution;
    int targetSum = 5;
    TreeNodePtr root = std::make_unique<TreeNode>(1);
    root->addChildren(std::make_unique<TreeNode>(2), std::make_unique<TreeNode>(3));
    bool has_path_sum = solution.hasPathSum(std::move(root), targetSum);
    ASSERT_EQ(has_path_sum, false);
  }
  {
    Solution solution;
    int targetSum = 0;
    bool has_path_sum = solution.hasPathSum(nullptr, targetSum);
    ASSERT_EQ(has_path_sum, false);
  }
  {
    Solution solution;
    int targetSum = 0;
    TreeNodePtr root = std::make_unique<TreeNode>(1);
    root->addChildren(std::make_unique<TreeNode>(2), nullptr);
    bool has_path_sum = solution.hasPathSum(nullptr, targetSum);
    ASSERT_EQ(has_path_sum, false);
  }
}