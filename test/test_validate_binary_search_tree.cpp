//
// Created by wfram on 2/22/23.
//

#include <gtest/gtest.h>

#include <validate_binary_search_tree.h>

TEST(validate_binary_search_tree, validate_binary_search_tree) {
  using Solution = validate_binary_search_tree::NormalSolution;
  {
    Solution solution;
    TreeNodePtr root = std::make_unique<TreeNode>(2);
    root->addChildren(std::make_unique<TreeNode>(1), std::make_unique<TreeNode>(3));
    bool is_valid = solution.isValidBST(std::move(root));
    ASSERT_EQ(is_valid, true);
  }
  {
    Solution solution;
    // TODO: check this test
    TreeNodePtr root = std::make_unique<TreeNode>(5);
    root->addChildren(std::make_unique<TreeNode>(1), std::make_unique<TreeNode>(4));
    root->right_->addChildren(std::make_unique<TreeNode>(3), std::make_unique<TreeNode>(6));
    //    bool is_valid = solution.isValidBST(std::move(root));
    //    ASSERT_EQ(is_valid, true);
  }
  {
    Solution solution;
    TreeNodePtr root = std::make_unique<TreeNode>(5);
    root->addChildren(std::make_unique<TreeNode>(4), std::make_unique<TreeNode>(6));
    root->right_->addChildren(std::make_unique<TreeNode>(3), std::make_unique<TreeNode>(7));
    bool is_valid = solution.isValidBST(std::move(root));
    ASSERT_EQ(is_valid, false);
  }
  {
    Solution solution;
    TreeNodePtr root = std::make_unique<TreeNode>(3);
    root->addChildren(std::make_unique<TreeNode>(1), std::make_unique<TreeNode>(5));
    root->left_->addChildren(std::make_unique<TreeNode>(0), std::make_unique<TreeNode>(2));
    root->right_->addChildren(std::make_unique<TreeNode>(4), std::make_unique<TreeNode>(6));
    bool is_valid = solution.isValidBST(std::move(root));
    ASSERT_EQ(is_valid, true);
  }
  {
    Solution solution;
    TreeNodePtr root = std::make_unique<TreeNode>(2);
    root->addChildren(std::make_unique<TreeNode>(2), std::make_unique<TreeNode>(2));
    bool is_valid = solution.isValidBST(std::move(root));
    ASSERT_EQ(is_valid, false);
  }
}