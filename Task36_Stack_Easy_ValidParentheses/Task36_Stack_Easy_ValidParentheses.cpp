#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    static bool isValid(std::string s) {
        std::stack<char> stack;
        for (int i = 0;i < s.size();i++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                stack.push(s[i]);
            }
            else if (stack.empty()) {
                return 0;
            }
            else if ((s[i] == ')') && (stack.top() == '(')) {
                stack.pop();
            }
            else if ((s[i] == ']') && (stack.top() == '[')) {
                stack.pop();
            }
            else if ((s[i] == '}') && (stack.top() == '{')) {
                stack.pop();
            }
            else {
                return 0;
            }
        }
        if (stack.empty()) {
            return 1;
        }
        return 0;
    }
};

int main()
{
    std::cout << Solution::isValid("()[]{}");
}