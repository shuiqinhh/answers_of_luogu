//B2105 矩阵乘法
#include <iostream>

int main()
{
  int n, m, k;
  std::cin >> n >> m >> k;
  int a[n][m], b[m][k], re[n][k] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      std::cin >> b[i][j];
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < k; y++) {
      int result = 0;
      for (int z = 0; z < m; z++) {
        result += a[x][z] * b[z][y];
      }
      re[x][y] = result;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      std::cout << re[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}