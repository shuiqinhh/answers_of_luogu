#include <iostream>

void towerofHanoi(int n, char Atower, char Btower, char Ctower)
{
  // 递归终止条件
  if (n == 1) {
    std::cout << "Move plate 1 from " << Atower << " to " << Ctower << std::endl;
    return;
  }
  // 将 n-1 个盘子从 A 塔移动到 B 塔 ，以 C 塔为辅助塔
  towerofHanoi(n - 1, Atower, Ctower, Btower);
  //    将第 n 个盘子从 A 塔移动到 C 塔
  std::cout << "Move plate " << n << " from " << Atower << " to " << Ctower << std::endl;
  // 将剩余的 n-1 个盘子从 B 塔移动到 C 塔，以 A 塔为辅助塔
  towerofHanoi(n - 1, Btower, Atower, Ctower);
}

int main()
{
  int n = 5;
  towerofHanoi(n, 'A', 'B', 'C');  // A 是起始塔，B 是辅助塔，C 是目标塔
  return 0;
}