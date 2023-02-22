//
// Created by wfram on 2/21/23.
//

#ifndef WF_ALGO_TREE_NODE_H
#define WF_ALGO_TREE_NODE_H

#include <memory>

class TreeNode;

using TreeNodePtr = std::unique_ptr<TreeNode>;

class TreeNode {
 public:
  explicit TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}

  explicit TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}

  TreeNode(int val, TreeNodePtr left, TreeNodePtr right)
      : val_(val), left_(std::move(left)), right_(std::move(right)) {}

  void addChildren(TreeNodePtr left, TreeNodePtr right) {
    left_ = std::move(left);
    right_ = std::move(right);
  }

  int val_;
  // TODO: do we need make them shared? For this case seems to be more than enough
  // TODO: do we need to move?
  TreeNodePtr left_;
  TreeNodePtr right_;
};

#endif  // WF_ALGO_TREE_NODE_H
