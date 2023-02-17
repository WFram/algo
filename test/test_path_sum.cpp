//
// Created by wfram on 2/18/23.
//

#include <gtest/gtest.h>

#include <path_sum.h>

template <class Solution>
void pass(path_sum::TreeNodePtr root, int targetSum) {
  Solution solution;
  bool has_path_sum = solution.hasPathSum(std::move(root), targetSum);
  std::cout << "Has? " << has_path_sum << std::endl;
}

int main() {
  using Solution = path_sum::NormalSolution;

  // TODO: do we need make them shared? For this case seems to be more than enough
  // TODO: do we need to move?
  {
    int targetSum = 22;
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(5);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(4), std::make_shared<path_sum::TreeNode>(8));
    addTreeNode(root->left, std::make_shared<path_sum::TreeNode>(11), nullptr);
    addTreeNode(root->right, std::make_shared<path_sum::TreeNode>(13), std::make_shared<path_sum::TreeNode>(4));
    addTreeNode(root->left->left, std::make_shared<path_sum::TreeNode>(7), std::make_shared<path_sum::TreeNode>(2));
    addTreeNode(root->right->right, nullptr, std::make_shared<path_sum::TreeNode>(1));
    pass<Solution>(std::move(root), targetSum);
  }

  {
    int targetSum = 5;
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(1);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(2), std::make_shared<path_sum::TreeNode>(3));
    pass<Solution>(std::move(root), targetSum);
  }

  {
    int targetSum = 0;
    pass<Solution>(nullptr, targetSum);
  }

  {
    int targetSum = 0;
    path_sum::TreeNodePtr root = std::make_shared<path_sum::TreeNode>(1);
    addTreeNode(root, std::make_shared<path_sum::TreeNode>(2), nullptr);
    pass<Solution>(std::move(root), targetSum);
  }

  return 0;
}