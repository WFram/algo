//
// Created by wfram on 2/9/23.
//

#include <palindrome_number.h>

bool palindrome_number::NormalSolution::isPalindrome(int x) {
  if (x < 0) return false;
  auto forward = std::to_string(x);
  auto backward = std::to_string(x);
  std::reverse(backward.begin(), backward.end());
  return (forward == backward);
}

bool palindrome_number::FastSolution::isPalindrome(int x) {
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

bool palindrome_number::MemoryEfficientSolution::isPalindrome(int x) {
  if (x < 0) return false;
  std::string s = std::to_string(x);
  for (int i = 0; i < s.size() / 2 + 1; i++)
    if (s[i] != s[s.size() - 1 - i]) return false;
  return true;
}
