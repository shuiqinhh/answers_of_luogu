#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  if (!(cin >> n)) return 0;

  // 如果没有盘子，直接输出 0
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  // 用 vector 来存大数的每一位，倒序存储
  // 例如数字 123，在 vector 里存为 {3, 2, 1}，方便处理进位
  vector<int> num;
  num.push_back(1);  // 初始值为 2^0 = 1

  // 执行 n 次乘以 2
  for (int i = 0; i < n; i++) {
    int carry = 0;  // 进位
    for (int j = 0; j < num.size(); j++) {
      int temp = num[j] * 2 + carry;  // 当前位乘2加上一轮的进位
      num[j] = temp % 10;             // 当前位保留个位
      carry = temp / 10;              // 计算向下一位的进位
    }
    // 如果乘完最高位还有进位，增加新的最高位
    if (carry > 0) {
      num.push_back(carry);
    }
  }

  // 最后需要减 1 (计算 2^n - 1)
  // 因为对于 n >= 1, 2^n 的个位数只可能是 2, 4, 8, 6，绝对不可能为 0
  // 所以个位直接减 1 是绝对安全的，不需要考虑复杂的借位问题
  num[0] -= 1;

  // 倒序输出结果（从最高位输出到最低位）
  for (int i = num.size() - 1; i >= 0; i--) {
    cout << num[i];
  }
  cout << endl;

  return 0;
}