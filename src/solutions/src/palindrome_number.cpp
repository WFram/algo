//
// Created by wfram on 2/9/23.
//

#include <iostream>
#include <string>

// https://leetcode.com/problems/palindrome-number/
class Solution {
 public:
  virtual bool isPalindrome(int x) = 0;
};

class NormalSolution : public Solution {
 public:
  bool isPalindrome(int x) override {
    if (x < 0) return false;
    auto forward = std::to_string(x);
    auto backward = std::to_string(x);
    std::reverse(backward.begin(), backward.end());
    return (forward == backward);
  }
};

class FastSolution : public Solution {
 public:
  bool isPalindrome(int x) override {
    int a = x, b;
    long long int rev{0};
    do {
      b = std::abs(a) % 10;
      rev *= 10;
      rev += b;
      a /= 10;
    } while (a != 0);

    return (rev == x);
  }
};

class MemoryEfficientSolution : public Solution {
 public:
  bool isPalindrome(int x) override {
    if (x < 0) return false;
    std::string s = std::to_string(x);
    for (int i = 0; i < s.size() / 2 + 1; i++)
      if (s[i] != s[s.size() - 1 - i]) return false;
    return true;
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
