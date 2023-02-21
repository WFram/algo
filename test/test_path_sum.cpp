//
// Created by wfram on 2/18/23.
//

#include <gtest/gtest.h>

#include <path_sum.h>

TEST(path_sum, path_sum) {
  using Solution = path_sum::NormalSolution;
  {
    Solution solution;
    int targetSum = 22;
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(5);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(4), std::make_shared<path_sum::TreeNode>(8));
    addTreeNode(root->left, std::make_shared<path_sum::TreeNode>(11), nullptr);
    addTreeNode(root->right, std::make_shared<path_sum::TreeNode>(13), std::make_shared<path_sum::TreeNode>(4));
    addTreeNode(root->left->left, std::make_shared<path_sum::TreeNode>(7), std::make_shared<path_sum::TreeNode>(2));
    addTreeNode(root->right->right, nullptr, std::make_shared<path_sum::TreeNode>(1));
    bool has_path_sum = solution.hasPathSum(std::move(root), targetSum);
    ASSERT_EQ(has_path_sum, true);
  }
  {
    Solution solution;
    int targetSum = 5;
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(1);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(2), std::make_shared<path_sum::TreeNode>(3));
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
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(1);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(2), nullptr);
    bool has_path_sum = solution.hasPathSum(nullptr, targetSum);
    ASSERT_EQ(has_path_sum, false);
  }
}