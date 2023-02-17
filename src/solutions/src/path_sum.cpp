//
// Created by wfram on 2/9/23.
//

#include <functional>
#include <iostream>
#include <memory>

struct TreeNode {
  int val;
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right)
      : val(val), left(std::move(left)), right(std::move(right)) {}
};

using TreeNodePtr = std::shared_ptr<TreeNode>;

void addTreeNode(TreeNodePtr root, TreeNodePtr left, TreeNodePtr right) {
  root->left = std::move(left);
  root->right = std::move(right);
}

// https://leetcode.com/problems/path-sum/
class Solution {
 public:
  virtual bool hasPathSum(TreeNodePtr root, int targetSum) = 0;
};

class NormalSolution : public Solution {
 public:
  void calculateSum(TreeNodePtr root, int sum) {
    if (root == nullptr) {
      return;
    }
    sum += root->val;

    if (root->left == nullptr and root->right == nullptr) {
      sums_.push_back(sum);
      return;
    };

    // TODO: it anyways calculates the whole sum, because it will call calculateSum from the same root
    calculateSum(std::move(root->left), sum);
    calculateSum(std::move(root->right), sum);
  }

  bool hasPathSum(TreeNodePtr root, int targetSum) override {
    calculateSum(std::move(root), 0);

    return std::count(sums_.begin(), sums_.end(), targetSum);
  }

 private:
  std::vector<int> sums_;
};

class FastSolution : public Solution {
 public:
  bool hasPathSum(TreeNodePtr root, int targetSum) override {
    if (!root) return false;
    targetSum -= root->val;
    if (targetSum == 0 and !root->left and !root->right) return true;
    return hasPathSum(std::move(root->left), targetSum) or hasPathSum(std::move(root->right), targetSum);
  }
};

class MemoryEfficientSolution : public Solution {
 public:
  bool hasPathSum(TreeNodePtr root, int targetSum, int sumSoFar = 0) {
    if (root == nullptr) return false;
    sumSoFar += root->val;
    if (sumSoFar == targetSum and root->left == nullptr and root->right == nullptr) return true;
    return (hasPathSum(std::move(root->left), targetSum, sumSoFar) or
            hasPathSum(std::move(root->right), targetSum, sumSoFar));
  }
};

template <class Solution>
void pass(TreeNodePtr root, int targetSum) {
  Solution solution;
  bool has_path_sum = solution.hasPathSum(std::move(root), targetSum);
  std::cout << "Has? " << has_path_sum << std::endl;
}

int main() {
  using Solution = NormalSolution;

  // TODO: do we need make them shared? For this case seems to be more than enough
  // TODO: do we need to move?
  {
    int targetSum = 22;
    TreeNodePtr root = std::make_shared<TreeNode>(5);
    addTreeNode(root, std::make_shared<TreeNode>(4), std::make_shared<TreeNode>(8));
    addTreeNode(root->left, std::make_shared<TreeNode>(11), nullptr);
    addTreeNode(root->right, std::make_shared<TreeNode>(13), std::make_shared<TreeNode>(4));
    addTreeNode(root->left->left, std::make_shared<TreeNode>(7), std::make_shared<TreeNode>(2));
    addTreeNode(root->right->right, nullptr, std::make_shared<TreeNode>(1));
    pass<Solution>(std::move(root), targetSum);
  }

  {
    int targetSum = 5;
    TreeNodePtr root = std::make_shared<TreeNode>(1);
    addTreeNode(root, std::make_shared<TreeNode>(2), std::make_shared<TreeNode>(3));
    pass<Solution>(std::move(root), targetSum);
  }

  {
    int targetSum = 0;
    pass<Solution>(nullptr, targetSum);
  }

  {
    int targetSum = 0;
    TreeNodePtr root = std::make_shared<TreeNode>(1);
    addTreeNode(root, std::make_shared<TreeNode>(2), nullptr);
    pass<Solution>(std::move(root), targetSum);
  }

  return 0;
}