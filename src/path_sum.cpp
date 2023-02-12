//
// Created by wfram on 2/9/23.
//

#include <functional>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

// https://leetcode.com/problems/path-sum/
class Solution {
 public:
  virtual bool hasPathSum(TreeNode *root, int targetSum) = 0;
};

class NormalSolution : public Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) override {
    if (root == nullptr) return false;
    if (root->left == nullptr and root->right == nullptr)
      if (root->val == 0) return false;
    bool result;
    sum_ += root->val;
    if (root->left != nullptr) {
      result = hasPathSum(root->left, targetSum);
      if (!result)
        result = hasPathSum(root->left, targetSum);
      else
        return result;
    }
    if (sum_ == targetSum)
      return true;
    else
      sum_ = 0;
    if (root->right != nullptr) {
      result = hasPathSum(root->right, targetSum);
      if (!result)
        result = hasPathSum(root->right, targetSum);
      else
        return result;
    }
    if (sum_ == targetSum)
      return true;
    else
      sum_ = 0;
    return false;
  }

 private:
  int sum_ = 0;
};

template <class Solution>
void pass(TreeNode *root, int targetSum) {
  Solution solution;
  bool has_path_sum = solution.hasPathSum(root, targetSum);
  std::cout << "Has? " << has_path_sum << std::endl;
}

int main() {
  using Solution = NormalSolution;
  {
    int targetSum = 22;
    // TODO: 1. check if we set nodes properly
    //       2. think of another way of setting nodes for a tree
    TreeNode third_rightrightright(1);
    TreeNode third_leftleftright(2);
    TreeNode third_leftleftleft(7);
    TreeNode second_rightright(4, nullptr, &third_rightrightright);
    TreeNode second_rightleft(13);
    TreeNode second_leftleft(11, &third_leftleftleft, &third_leftleftright);
    TreeNode first_right(8, &second_rightleft, &second_rightright);
    TreeNode first_left(4, &second_leftleft, nullptr);
    TreeNode root(5, &first_left, &first_right);
    pass<Solution>(&root, targetSum);
  }
  {
    int targetSum = 5;
    TreeNode first_right(3);
    TreeNode first_left(2);
    TreeNode root(1, &first_left, &first_right);
    pass<Solution>(&root, targetSum);
  }
  {
    int targetSum = 0;
    TreeNode root(0);
    pass<Solution>(&root, targetSum);
  }
  return 0;
}