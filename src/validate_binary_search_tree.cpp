//
// Created by wfram on 2/5/23.
//

#include <functional>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/validate-binary-search-tree/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  virtual bool isValidBST(TreeNode *root) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isValidBST(TreeNode *root) override {
    std::function<bool(TreeNode *)> in_order = [&](TreeNode *node) {
      if (node == nullptr) return true;
      if (!in_order(node->left)) return false;
      if (node->val <= previous_value_) return false;
      previous_value_ = node->val;
      return in_order(node->right);
    };

    if (!root->left and !root->right) return true;
    return in_order(root);
  }

 private:
  long int previous_value_{std::numeric_limits<long int>::min()};
};

template <class Solution>
void pass(TreeNode *root) {
  Solution solution;
  bool is_valid = solution.isValidBST(root);
  std::cout << "Is valid? " << is_valid << std::endl;
}

int main() {
  using Solution = NormalSolution;
  {
    TreeNode first_left(1);
    TreeNode first_right(3);
    TreeNode root(2, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    TreeNode first_left(1);
    TreeNode second_left(3);
    TreeNode second_right(6);
    TreeNode first_right(4, &second_left, &second_right);
    TreeNode root(5, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    // False
    TreeNode first_left(4);
    TreeNode second_left(3);
    TreeNode second_right(7);
    TreeNode first_right(6, &second_left, &second_right);
    TreeNode root(5, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    // True
    TreeNode second_left_left(0);
    TreeNode second_left_right(2);
    TreeNode second_right_left(4);
    TreeNode second_right_right(6);
    TreeNode first_right(5, &second_right_left, &second_right_right);
    TreeNode first_left(1, &second_left_left, &second_left_right);
    TreeNode root(3, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    TreeNode first_left(2);
    TreeNode first_right(2);
    TreeNode root(2, &first_left, &first_right);
    pass<Solution>(&root);
  }
  return 0;
}