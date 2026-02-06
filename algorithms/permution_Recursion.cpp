//全排列递归
#include <iomanip>
#include <iostream>
#include <vector>
//注意引用传递
void permute(std::vector<int> & nums, int start, int end, std::vector<std::vector<int>> & results)
{
  if (start == end) {
    results.push_back(nums);
    return;
  }
  for (int i = start; i < end; i++) {
    std::swap(nums[start], nums[i]);
    permute(nums, start + 1, end, results);
    std::swap(nums[start], nums[i]);
  }
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> nums;
  for (int i = 1; i <= n; i++) {
    nums.push_back(i);
  }
  std::vector<std::vector<int>> results;
  permute(nums, 0, n, results);
  for (int i = 0; i < (int)results.size(); i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::setw(5) << results[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}