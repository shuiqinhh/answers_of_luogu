#include <cstring>
#include <iostream>
#include <stack>

int main()
{
  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    std::string s;
    std::cin >> s;
    std::stack<char> mystack;
    mystack.push(s[0]);
    for (int j = 1; j < (int)s.length(); ++j) {
      if (s[j] == '(' || s[j] == '[' || s[j] == '{') {
        mystack.push(s[j]);
      } else if (mystack.top() == '(' && s[j] == ')') {
        mystack.pop();
        continue;
      } else if (mystack.top() == '[' && s[j] == ']') {
        mystack.pop();
        continue;
      } else if (mystack.top() == '{' && s[j] == '}') {
        mystack.pop();
        continue;
      }
    }
    if (!mystack.empty()) {
      std::cout << "NO" << std::endl;
    } else {
      std::cout << "YES" << std::endl;
    }
  }
  return 0;
}