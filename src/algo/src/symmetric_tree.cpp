//
// Created by wfram on 2/28/23.
//

#include <symmetric_tree.h>

bool symmetric_tree::NormalSolution::isSymmetric(TreeNodePtr root) {
  std::function<bool(TreeNodePtr, TreeNodePtr)> isMirror = [&](TreeNodePtr left, TreeNodePtr right) {
    if (!left and !right) return true;
    if (!left or !right) return false;
    if (left->val_ != right->val_) return false;
    return isMirror(std::move(left->left_), std::move(right->right_)) and
           isMirror(std::move(left->right_), std::move(right->left_));
  };

  if (!root) return true;
  return isMirror(std::move(root->left_), std::move(root->right_));
}
