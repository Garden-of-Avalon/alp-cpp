// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another
// expression.
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> temp;
        for (auto i = tokens.begin(); i != tokens.end(); ++i) {
            if (*i == "+") {
                int x = temp.top();
                temp.pop();
                temp.top() += x;
            } else if (*i == "-") {
                int x = temp.top();
                temp.pop();
                temp.top() -= x;
            } else if (*i == "*") {
                int x = temp.top();
                temp.pop();
                temp.top() *= x;
            } else if (*i == "/") {
                int x = temp.top();
                temp.pop();
                temp.top() /= x;
            } else
                temp.push(stoi(*i));
        }
        return temp.top();
    }
};