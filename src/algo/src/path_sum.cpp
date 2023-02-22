//
// Created by wfram on 2/9/23.
//

#include <path_sum.h>

void path_sum::NormalSolution::calculateSum(TreeNodePtr root, int sum) {
  if (root == nullptr) {
    return;
  }
  sum += root->val_;

  if (root->left_ == nullptr and root->right_ == nullptr) {
    sums_.push_back(sum);
    return;
  };

  // TODO: it anyways calculates the whole sum, because it will call calculateSum from the same root
  calculateSum(std::move(root->left_), sum);
  calculateSum(std::move(root->right_), sum);
}

bool path_sum::NormalSolution::hasPathSum(TreeNodePtr root, int targetSum) {
  calculateSum(std::move(root), 0);

  return std::count(sums_.begin(), sums_.end(), targetSum);
}

bool path_sum::FastSolution::hasPathSum(TreeNodePtr root, int targetSum) {
  if (!root) return false;
  targetSum -= root->val_;
  if (targetSum == 0 and !root->left_ and !root->right_) return true;
  return hasPathSum(std::move(root->left_), targetSum) or hasPathSum(std::move(root->right_), targetSum);
}

bool path_sum::MemoryEfficientSolution::hasPathSum(TreeNodePtr root, int targetSum, int sumSoFar) {
  if (root == nullptr) return false;
  sumSoFar += root->val_;
  if (sumSoFar == targetSum and root->left_ == nullptr and root->right_ == nullptr) return true;
  return (hasPathSum(std::move(root->left_), targetSum, sumSoFar) or
          hasPathSum(std::move(root->right_), targetSum, sumSoFar));
}