//P5613 黑蚊子多
#include <iostream>

int main()
{
  int n, m, k;
  int time = 0, now = 0;
  std::cin >> n >> m >> k;
  int a[k];
  for (int i = 0; i < k; i++) {
    std::cin >> a[i];
  }
  while (now < n) {
    now += m;
    ++time;
    for (int i = 0; i < k; i++) {
      if (now == a[i]) {
        ++m;
      }
    }
  }
  std::cout << time;
  return 0;
}