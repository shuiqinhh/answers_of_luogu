//sorting algorithms
#include <algorithm>
#include <iostream>
#include <vector>
//冒泡排序
int bubbleSort(int & a[], int times)
{
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
  return times;
}

//桶排序
void binSort(float arr[], int n)
{
  if (n <= 1) return;
  float maxele = arr[0];
  float minele = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > maxele) maxele = arr[i];
    if (arr[i] < minele) minele = arr[i];
  }
  if (maxele == minele) return;
  std::vector<std::vector<float>> bins(n);
  double range = (maxele - minele) / n;
  for (int i = 0; i < n; i++) {
    int index = (arr[i] - minele) / range;
    if (index == n) index--;
    bins[index].push_back(arr[i]);
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (!bins[i].empty()) {
      std::sort(bins[i].begin(), bins[i].end());
      for (int j = 0; j < (int)bins[i].size(); j++) {
        arr[index++] = bins[i][j];
      }
    }
  }
}

//主函数
int main()
{
  int a[4] = {4, 3, 2, 1};
  int times = 0;
  int n = bubbleSort(a, times);
  for (int i = 0; i < 4; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  std::cout << n << std::endl;
  return 0;
}