//B2158 谁考了第k名
#include <iostream>
#include <vector>
int main()
{
  int n, k;
  std::cin >> n >> k;
  std::vector<int> id;
  std::vector<double> score;
  int a;
  double b;
  for (int i = 0; i < n; i++) {
    std::cin >> a >> b;
    id.push_back(a);
    score.push_back(b);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (score[i] < score[j]) {
        double c = score[i];
        score[i] = score[j];
        score[j] = c;
        int d = id[i];
        id[i] = id[j];
        id[j] = d;
      }
    }
  }
  printf("%d %g\n", id[k - 1], score[k - 1]);
  return 0;
}