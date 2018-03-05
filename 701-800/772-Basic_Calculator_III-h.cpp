// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus
// + or minus sign -, non-negative integers and empty spaces .

// The expression string contains only non-negative integers, +, -, *, /
// operators , open ( and closing parentheses ) and empty spaces . The integer
// division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate
// results will be in the range of [-2147483648, 2147483647].

// Some examples:

// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12

// Note: Do not use the eval built-in library function.

class Solution {
  public:
    int calculate(string s) {
        stack<long long> nums;
        stack<char> ops;

        auto calculate = [&]() {
            long long curr_num = nums.top();
            nums.pop();
            while (!ops.empty() && ops.top() != '(') {
                if (ops.top() == '*')
                    nums.top() *= curr_num;
                else if (ops.top() == '/')
                    nums.top() /= curr_num;
                else if (ops.top() == '+')
                    nums.top() += curr_num;
                else if (ops.top() == '-')
                    nums.top() -= curr_num;

                curr_num = nums.top();
                nums.pop();
                ops.pop();
            }
            nums.push(curr_num);
        };

        istringstream expin(s); // expression in
        char curr_char;
        long long curr_num;

        while (expin >> ws && !expin.eof()) {
            if (isdigit(expin.peek())) {
                expin >> curr_num;
                nums.push(curr_num);

                if (!ops.empty() && (ops.top() == '*' || ops.top() == '/'))
                    calculate();
            } else {
                expin >> curr_char;
                if (curr_char == ')') {
                    calculate();
                    ops.pop();
                } else {
                    if (curr_char == '+' || curr_char == '-')
                        calculate();
                    ops.push(curr_char);
                }
            }
        }

        calculate();

        return nums.empty() ? 0 : nums.top();
    }
};