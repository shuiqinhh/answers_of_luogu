#include <iostream>

int main()
{
  int a[7], b[7];
  int c[7];
  for (int i = 0; i < 7; i++) {
    c[i] = 0;
  }
  int n;
  std::cin >> n;
  for (int i = 0; i < 7; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) {
    int common = 0;
    for (int i = 0; i < 7; i++) std::cin >> b[i];
    for (int j = 0; j < 7; j++) {
      for (int k = 0; k < 7; k++) {
        if (b[k] == a[j]) {
          ++common;
        }
      }
    }
    ++c[7 - common];
  }
  for (int i = 0; i < 7; i++) {
    std::cout << c[i] << " ";
  }
  return 0;
}