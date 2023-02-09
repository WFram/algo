//
// Created by wfram on 2/9/23.
//

#include <string>
#include <iostream>

// https://leetcode.com/problems/palindrome-number/
class Solution {
 public:
  virtual bool isPalindrome(int x) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isPalindrome(int x) override {
    auto forward = std::to_string(x);
    auto backward = std::to_string(x);
    std::reverse(backward.begin(), backward.end());
    return (forward == backward);
  }
};

template <class Solution>
void pass(int x) {
  Solution solution;
  bool result = solution.isPalindrome(x);
  std::cout << "Is a palindrome? " << result << std::endl;
}

int main() {
  using Solution = NormalSolution;
  pass<Solution>(121);
  pass<Solution>(-121);
  pass<Solution>(10);
}
