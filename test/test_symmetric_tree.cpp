//
// Created by wfram on 2/28/23.
//

#include <gtest/gtest.h>

#include <symmetric_tree.h>

TEST(symmetric_tree, symmetric_tree) {
  using Solution = symmetric_tree::NormalSolution;
  {
    Solution solution;
    auto root = std::make_unique<TreeNode>(1);
    root->addChildren(std::make_unique<TreeNode>(2), std::make_unique<TreeNode>(2));
    root->left_->addChildren(std::make_unique<TreeNode>(3), std::make_unique<TreeNode>(4));
    root->right_->addChildren(std::make_unique<TreeNode>(4), std::make_unique<TreeNode>(3));
    bool result = solution.isSymmetric(std::move(root));
    ASSERT_EQ(result, true);
  }
  {
    Solution solution;
    auto root = std::make_unique<TreeNode>(1);
    root->addChildren(std::make_unique<TreeNode>(2), std::make_unique<TreeNode>(2));
    root->left_->addChildren(nullptr, std::make_unique<TreeNode>(3));
    root->right_->addChildren(nullptr, std::make_unique<TreeNode>(3));
    bool result = solution.isSymmetric(std::move(root));
    ASSERT_EQ(result, false);
  }
}
