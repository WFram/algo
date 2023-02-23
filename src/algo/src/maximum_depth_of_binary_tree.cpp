//
// Created by wfram on 2/17/23.
//

#include <maximum_depth_of_binary_tree.h>

int maximum_depth_of_binary_tree::NormalSolution::maxDepth(TreeNodePtr root) {
  if (!root) return 0;
  return 1 + std::max(maxDepth(std::move(root->left_)), maxDepth(std::move(root->right_)));
}
