//
// Created by wfram on 2/5/23.
//

#include <functional>
#include <iostream>
#include <vector>

template <class Solution>
void pass(TreeNode *root) {
  Solution solution;
  bool is_valid = solution.isValidBST(root);
  std::cout << "Is valid? " << is_valid << std::endl;
}

int main() {
  using Solution = NormalSolution;
  {
    // True
    TreeNode first_left(1);
    TreeNode first_right(3);
    TreeNode root(2, &first_left, &first_right);
    pass<Solution>(&root);
  }
  {
    // False
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
    // False
    TreeNode first_left(2);
    TreeNode first_right(2);
    TreeNode root(2, &first_left, &first_right);
    pass<Solution>(&root);
  }
  return 0;
}