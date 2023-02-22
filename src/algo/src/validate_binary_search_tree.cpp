//
// Created by wfram on 2/21/23.
//

#include <validate_binary_search_tree.h>

bool validate_binary_search_tree::NormalSolution::isValidBST(TreeNodePtr root) {
  std::function<bool(TreeNodePtr)> in_order = [&](TreeNodePtr node) {
    if (node == nullptr) return true;
    if (!in_order(std::move(node->left_))) return false;
    if (node->val_ <= previous_value_) return false;
    previous_value_ = node->val_;
    return in_order(std::move(node->right_));
  };

  if (!root->left_ and !root->right_) return true;
  return in_order(std::move(root));
}