//
// Created by wfram on 2/17/23.
//

#include <maximum_depth_of_binary_tree.h>

int maximum_depth_of_binary_tree::NormalSolution::maxDepth(TreeNodePtr root) {
  if (!root) return 0;
  return 1 + std::max(maxDepth(std::move(root->left_)), maxDepth(std::move(root->right_)));
}

int maximum_depth_of_binary_tree::MemoryEfficientSolution::maxDepth(TreeNodePtr root) {
  int result = 0, current_depth = 0;
  TreeNodePtr current = std::move(root), stack = nullptr;

  while (current or stack) {
    if (current) {
      current->val_ = current_depth;

      const TreeNodePtr next = std::move(current->left_);
      current->left_ = std::move(stack);
      stack = std::move(current);
      // TODO: carry on from here (find out the meaning)
      current = std::move(const_cast<TreeNodePtr&>(next));
      ++current_depth;
    } else {
      result = std::max(result, current_depth);

      current = std::move(stack->right_);
      current_depth = stack->val_ + 1;
      stack = std::move(stack->left_);
    }
  }

  return result;
}
