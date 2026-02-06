//P1125 笨小猴
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
  std::string s;
  std::cin >> s;
  int max = 0, min = 100;
  std::vector<int> nums;
  for (int i = 0; i < (int)s.length(); i++) {
    nums.push_back(std::count(s.begin(), s.end(), s[i]));
  }
  for (int i = 0; i < (int)nums.size(); i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
    if (nums[i] < min) {
      min = nums[i];
    }
  }
  bool prime = true;
  for (int i = 2; i < max - min; i++) {
    if ((max - min) % i == 0) prime = false;
  }
  if (max - min == 0 || max - min == 1) {
    prime = false;
  }
  if (prime) {
    std::cout << "Lucky Word" << std::endl;
    std::cout << max - min;
  } else {
    std::cout << "No Answer" << std::endl;
    std::cout << 0;
  }
  return 0;
}