//
// Created by wfram on 2/5/23.
//

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
    bool return_value{true};

    if (root->left != nullptr)
      if (root->left->val > root->val) return_value = false;
    if (root->right != nullptr)
      if (root->right->val < root->val) return_value = false;

    if (root->val < min_value_) min_value_ = root->val;
    if (root->val > max_value_) max_value_ = root->val;

    pairs.emplace_back(min_value_, max_value_);

    // TODO: we should somehow move step by step from one level to another
    // TODO: make it in one line (return_value)
    if (root->left != nullptr) {
      pairs.emplace_back(min_value_, max_value_);
      return_value &= isValidBST(root->left);
    }

    if (root->right != nullptr) {
      return_value &= isValidBST(root->right);
    }
    return return_value;
  }

 private:
  int min_value_{std::numeric_limits<int>::max()};
  int max_value_{std::numeric_limits<int>::min()};
  std::vector<std::pair<int, int>> pairs;
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
    TreeNode first_left(4);
    TreeNode second_left(3);
    TreeNode second_right(7);
    TreeNode first_right(6, &second_left, &second_right);
    TreeNode root(5, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    TreeNode second_left_left(0);
    TreeNode second_left_right(2);
    TreeNode second_right_left(4);
    TreeNode second_right_right(6);
    TreeNode first_right(5, &second_right_left, &second_right_right);
    TreeNode first_left(1, &second_left_left, &second_left_right);
    TreeNode root(3, &first_left, &first_right);
    pass<Solution>(&root);
  }
  return 0;
}