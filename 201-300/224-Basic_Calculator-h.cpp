// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus
// + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:

// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23

// Note: Do not use the eval built-in library function.

class Solution {
  public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        auto calculate = [&](int curr_num) {
            while (!ops.empty() && ops.top() != '(') {
                if (ops.top() == '+')
                    nums.top() += curr_num;
                else
                    nums.top() -= curr_num;
                curr_num = nums.top();
                nums.pop();
                ops.pop();
            }
            nums.push(curr_num);
        };

        istringstream expin(s); // expression in
        char curr_char;
        int curr_num;

        while (expin >> ws) {
            if (isdigit(expin.peek())) {
                expin >> curr_num;
                calculate(curr_num);
            } else {
                expin >> curr_char;
                if (curr_char == ')' && !ops.empty() && ops.top() == '(') {
                    ops.pop();

                    curr_num = nums.top();
                    nums.pop();

                    calculate(curr_num);
                } else
                    ops.push(curr_char);
            }
        }

        return nums.empty() ? 0 : nums.top();
    }
};