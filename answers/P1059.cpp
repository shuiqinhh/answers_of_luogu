//P1059 明明的随机数
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
  int n;
  std::cin >> n;
  std::vector<int> answers;
  int nums[n];
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  answers.push_back(nums[0]);
  for (int i = 1; i < n; i++) {
    bool re = false;
    for (int j = 0; j < (int)answers.size(); j++) {
      if (answers[j] == nums[i]) {
        re = true;
      }
    }
    if (!re) {
      answers.push_back(nums[i]);
    }
  }
  std::cout << (int)answers.size() << std::endl;
  std::sort(answers.begin(), answers.end());
  for (int i = 0; i < (int)answers.size(); i++) {
    std::cout << answers[i] << " ";
  }
  return 0;
}