//P1116 车厢重组 冒泡排序
#include <iostream>

int main()
{
  int n, times;
  times = 0;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
        times++;
      }
    }
    if (!swapped) {
      break;
    }
  }
  std::cout << times;
  return 0;
}