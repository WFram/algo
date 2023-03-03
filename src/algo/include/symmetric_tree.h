//
// Created by wfram on 2/28/23.
//

#ifndef WF_ALGO_SYMMETRIC_TREE_H
#define WF_ALGO_SYMMETRIC_TREE_H

#include <functional>

#include <tree_node.h>

namespace symmetric_tree {

class Solution {
 public:
  virtual bool isSymmetric(TreeNodePtr root) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isSymmetric(TreeNodePtr root) override;
};

}  // namespace symmetric_tree

#endif  // WF_ALGO_SYMMETRIC_TREE_H
