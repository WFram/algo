//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <palindrome_number.h>

template <class Solution>
void pass(int x) {
  Solution solution;
  bool result = solution.isPalindrome(x);
  std::cout << "Is a palindrome? " << result << std::endl;
}

int main() {
  using Solution = palindrome_number::NormalSolution;
  pass<Solution>(121);
  pass<Solution>(-121);
  pass<Solution>(10);
}