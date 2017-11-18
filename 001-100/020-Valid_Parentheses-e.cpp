// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid
// but "(]" and "([)]" are not.

class Solution {
  public:
    bool isValid(string s) {
        stack<char> tempstack;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                tempstack.push(c);
            else if (tempstack.empty() ||
                     (c == ')' && tempstack.top() != '(') ||
                     (c == '}' && tempstack.top() != '{') ||
                     (c == ']' && tempstack.top() != '['))
                return false;
            else
                tempstack.pop();
        }
        return tempstack.empty();
    }
};