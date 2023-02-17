//
// Created by wfram on 2/17/23.
//

#include <maximum_depth_of_binary_tree.h>

int maximum_depth_of_binary_tree::NormalSolution::maxDepth(TreeNode *root) {
  // TODO: once we understand there is a node, we increment counter
  //    idea we shift each time SHIFT
  if (!root) return 0;
  counter = counter << 1;
  // TODO: boolean?
  counter = static_cast<unsigned char>(maxDepth(root->left) | maxDepth(root->right));
  return counter;
}
