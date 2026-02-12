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

//箱子排序
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

//基数排序
void radixSort(std::vector<int> & arr)
{
  int max = *std::max_element(arr.begin(), arr.end());
  int n = 0;
  while (max >= 1) {
    max /= 10;
    n++;
  }
  int * count = new int[10];             // 计数器，也就是0~9共10个桶
  int * tem = new int[(int)arr.size()];  // 临时数组，和计数排序的临时数组作用一样
  int radix = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      count[j] = 0;
    }
    for (int j = 0; j < (int)arr.size(); j++) {
      // 计数，方便后续获得每个数的index
      count[(arr[j] / radix) % 10]++;
    }
    for (int j = 1; j < 10; j++) {
      count[j] += count[j - 1];
    }
    for (int j = (int)arr.size() - 1; j >= 0; j--) {
      // 将桶里的元素取出来
      int index = count[(arr[j] / radix) % 10] - 1;
      tem[index] = arr[j];
      count[(arr[j] / radix) % 10]--;
    }
    for (int j = 0; j < (int)arr.size(); j++) {
      arr[j] = tem[j];
    }
    radix *= 10;
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
  std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
  radixSort(arr);
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}