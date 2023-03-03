//
// Created by wfram on 2/21/23.
//

#ifndef WF_ALGO_VALIDATE_BINARY_SEARCH_TREE_H
#define WF_ALGO_VALIDATE_BINARY_SEARCH_TREE_H

#include <functional>

#include <tree_node.h>

namespace validate_binary_search_tree {

// https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
 public:
  virtual bool isValidBST(TreeNodePtr root) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isValidBST(TreeNodePtr root);

 private:
  long int previous_value_{std::numeric_limits<long int>::min()};
};

class MemoryEfficientSolution : public Solution {
 public:

};

}  // namespace validate_binary_search_tree

#endif  // WF_ALGO_VALIDATE_BINARY_SEARCH_TREE_H
