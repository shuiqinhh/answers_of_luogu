//P2669 金币
#include <iostream>

int main()
{
  int days = 0, totalcoins = 0, totaldays = 0, j;
  std::cin >> days;
  for (int i = 1; i <= days; i++) {
    totalcoins += i * i;
    totaldays += i;
    if (days - totaldays < i + 1) {
      j = i;
      break;
    }
  }
  totalcoins += (j + 1) * (days - totaldays);
  std::cout << totalcoins;
  return 0;
}