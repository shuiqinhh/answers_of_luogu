#include <cstring>
#include <iostream>
#include <vector>
class numstack
{
public:
  std::vector<unsigned long long> stack;
  void push(unsigned long long x) { stack.push_back(x); }
  void pop()
  {
    if ((int)stack.size() == 0) {
      std::cout << "Empty" << std::endl;
    } else {
      stack.pop_back();
    }
  }
  void query()
  {
    if ((int)stack.size() == 0) {
      std::cout << "Anguei!" << std::endl;
    } else {
      std::cout << stack[(int)stack.size() - 1] << std::endl;
    }
  }
  void size() { std::cout << (int)stack.size() << std::endl; }
};

int main()
{
  int t, n;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    numstack mystack;
    for (int j = 0; j < n; j++) {
      std::string s;
      std::cin >> s;
      if (s == "push") {
        unsigned long long x;
        std::cin >> x;
        mystack.push(x);
      } else if (s == "pop") {
        mystack.pop();
      } else if (s == "query") {
        mystack.query();
      } else if (s == "size") {
        mystack.size();
      }
    }
  }
  return 0;
}