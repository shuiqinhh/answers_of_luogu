//P1996 约瑟夫问题 链表法
#include <iostream>
#include <list>

void Josephus(int n, int m)
{
  std::list<int> people;
  for (int i = 1; i <= n; i++) {
    people.push_back(i);
  }
  auto it = people.begin();  //list链表begin方法返回的实际是一个迭代器
  while ((int)people.size() > 1) {
    for (int i = 1; i <= m - 1; i++) {
      ++it;
      if (it == people.end()) {
        it = people.begin();
      }
    }
    std::cout << *it << " ";
    it = people.erase(it);  //返回指向删除元素后的地址,如果删除的是最后一个元素，则还是返回end
    if (it == people.end()) {
      it = people.begin();
    }
  }
  std::cout << people.front();
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  Josephus(n, m);
  return 0;
}
