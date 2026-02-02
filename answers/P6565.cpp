//P6565 最急救助
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main()
{
  int n;
  std::cin >> n;
  std::string name[n];
  int nums[n];
  for (int i = 0; i < n; i++) {
    nums[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> name[i];
    std::string s;
    std::cin >> s;
    for (int j = 0; j < (int)s.length() - 2; j++) {
      if (s[j] == 's' && s[j + 1] == 'o' && s[j + 2] == 's') {
        ++nums[i];
      }
    }
  }
  int max = *std::max_element(nums, nums + n);
  std::vector<int> list;
  for (int i = 0; i < n; i++) {
    if (nums[i] == max) {
      list.push_back(i);
    }
  }
  for (int i = 0; i < (int)list.size(); i++) {
    std::cout << name[list[i]] << " ";
  }
  std::cout << std::endl;
  std::cout << max;
  return 0;
}