//
// Created by wfram on 2/17/23.
//

#ifndef WF_LEETCODE_PALINDROME_NUMBER_H
#define WF_LEETCODE_PALINDROME_NUMBER_H

#include <iostream>
#include <string>

// https://leetcode.com/problems/palindrome-number/
namespace palindrome_number {

class Solution {
 public:
  virtual bool isPalindrome(int x) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isPalindrome(int x) override;
};

// Sample solution
class FastSolution : public Solution {
 public:
  bool isPalindrome(int x) override;
};

// Sample solution
class MemoryEfficientSolution : public Solution {
 public:
  bool isPalindrome(int x) override;
};

}

#endif  // WF_LEETCODE_PALINDROME_NUMBER_H
