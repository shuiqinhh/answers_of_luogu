//P6206 Another cow number game G
#include <iostream>

int main()
{
  long long n;
  int score = 0;
  std::cin >> n;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      ++score;
    } else {
      n = n * 3 + 1;
      ++score;
    }
  }
  std::cout << score;
  return 0;
}