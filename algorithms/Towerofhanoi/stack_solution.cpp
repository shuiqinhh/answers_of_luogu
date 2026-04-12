#include <iostream>
#include <stack>

// 定义汉诺塔任务的结构体
struct Task
{
  int n;      // 盘子数量
  char src;   // 起点柱子
  char aux;   // 辅助柱子
  char dest;  // 终点柱子
  int num;    //盘子编号
};

void hanoiStack(int n, char src, char aux, char dest)
{
  std::stack<Task> s;

  // 将初始大任务压入栈中
  s.push({n, src, aux, dest, n});

  while (!s.empty()) {
    // 取出栈顶任务并弹出
    Task t = s.top();
    s.pop();

    if (t.n == 1) {
      // 如果只有一个盘子，直接移动（相当于真正执行动作）
      std::cout << "Move plate " << t.num << " from " << t.src << " to " << t.dest << std::endl;
    } else {
      // 重点：因为栈是后进先出，所以压栈顺序要与实际执行顺序相反！

      // 实际执行步骤 3：将 n-1 个盘子从 aux 移到 dest (最后执行，最先压栈)
      s.push({t.n - 1, t.aux, t.src, t.dest, t.num - 1});

      // 实际执行步骤 2：将最大的 1 个盘子从 src 移到 dest (中间执行)
      // 这里为了通用，直接压入一个 n=1 的任务，它出栈时就会触发打印
      s.push({1, t.src, t.aux, t.dest, t.num});
      // 实际执行步骤 1：将 n-1 个盘子从 src 移到 aux (最先执行，最后压栈)
      s.push({t.n - 1, t.src, t.dest, t.aux, t.num - 1});
    }
  }
}

int main()
{
  int n = 4;  // 以 4 个盘子为例
  hanoiStack(n, 'A', 'B', 'C');
  return 0;
}