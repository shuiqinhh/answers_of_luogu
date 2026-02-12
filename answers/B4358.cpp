//B4358 奇偶校验
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
  int n;
  std::vector<int> a;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    a.push_back(input);
  }
  int total = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 7; j >= 0; j--) {
      while (a[i] >= std::pow(2, j)) {
        a[i] -= std::pow(2, j);
        ++total;
      }
    }
  }
  std::cout << total << " ";
  if (total % 2 == 1) {
    std::cout << 1;
  } else {
    std::cout << 0;
  }
  return 0;
}