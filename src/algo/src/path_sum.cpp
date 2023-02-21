//
// Created by wfram on 2/9/23.
//

#include <path_sum.h>

void path_sum::addTreeNode(TreeNodePtr root, TreeNodePtr left, TreeNodePtr right) {
  root->left = std::move(left);
  root->right = std::move(right);
}

void path_sum::NormalSolution::calculateSum(TreeNodePtr root, int sum) {
  if (root == nullptr) {
    return;
  }
  sum += root->val;

  if (root->left == nullptr and root->right == nullptr) {
    sums_.push_back(sum);
    return;
  };

  // TODO: it anyways calculates the whole sum, because it will call calculateSum from the same root
  calculateSum(std::move(root->left), sum);
  calculateSum(std::move(root->right), sum);
}

bool path_sum::NormalSolution::hasPathSum(TreeNodePtr root, int targetSum) {
  calculateSum(std::move(root), 0);

  return std::count(sums_.begin(), sums_.end(), targetSum);
}

bool path_sum::FastSolution::hasPathSum(TreeNodePtr root, int targetSum) {
  if (!root) return false;
  targetSum -= root->val;
  if (targetSum == 0 and !root->left and !root->right) return true;
  return hasPathSum(std::move(root->left), targetSum) or hasPathSum(std::move(root->right), targetSum);
}

bool path_sum::MemoryEfficientSolution::hasPathSum(TreeNodePtr root, int targetSum, int sumSoFar) {
  if (root == nullptr) return false;
  sumSoFar += root->val;
  if (sumSoFar == targetSum and root->left == nullptr and root->right == nullptr) return true;
  return (hasPathSum(std::move(root->left), targetSum, sumSoFar) or
          hasPathSum(std::move(root->right), targetSum, sumSoFar));
}