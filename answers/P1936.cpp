//P1936 水晶灯火灵 性质二为Fibonacci数
#include <iostream>

int main()
{
  long long m, n, k;
  std::cin >> k;
  m = 1;
  n = 1;
  while (m + n < k) {
    long long temp = m;
    m = n;
    n += temp;
  }
  std::cout << "m=" << m << std::endl << "n=" << n;
  return 0;
}