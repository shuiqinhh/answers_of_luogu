//P2705 小球
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
  int red, blue, c, d, e;
  std::vector<int> score;
  std::cin >> red >> blue >> c >> d >> e;
  for (int k = 0; k <= (red < blue ? red : blue); k++) {
    int a = e * 2 * k + c * (red - k) + d * (blue - k);
    score.push_back(a);
  }
  std::sort(score.begin(), score.end(), std::greater<int>());  //降序
  std::cout << score[0];
  return 0;
}