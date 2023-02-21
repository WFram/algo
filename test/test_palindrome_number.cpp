//
// Created by wfram on 2/17/23.
//

#include <gtest/gtest.h>

#include <palindrome_number.h>

TEST(test_palindrome_number, test_palindrome_number) {
  using Solution = palindrome_number::NormalSolution;
  Solution solution;
  bool result = solution.isPalindrome(121);
  ASSERT_EQ(result, true);
  result = solution.isPalindrome(-121);
  ASSERT_EQ(result, false);
  result = solution.isPalindrome(10);
  ASSERT_EQ(result, false);
}