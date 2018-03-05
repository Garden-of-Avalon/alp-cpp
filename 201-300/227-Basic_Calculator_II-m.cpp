// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, /
// operators and empty spaces . The integer division should truncate toward
// zero.

// You may assume that the given expression is always valid.

// Some examples:

// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5

// Note: Do not use the eval built-in library function.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

class Solution {
  public:
    int calculate(string s) {
        stack<long long> nums;
        stack<char> ops;

        auto muldiv = [&]() {
            long long curr_num = nums.top();
            nums.pop();
            while (!ops.empty() && ops.top() != '+' && ops.top() != '-') {
                if (ops.top() == '*')
                    nums.top() *= curr_num;
                else if (ops.top() == '/')
                    nums.top() /= curr_num;
                curr_num = nums.top();
                nums.pop();
                ops.pop();
            }
            nums.push(curr_num);
        };

        auto addminus = [&]() {
            long long curr_num = nums.top();
            nums.pop();
            while (!ops.empty()) {
                if (ops.top() == '+')
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
                    muldiv();

            } else {
                expin >> curr_char;

                if (curr_char == '+' || curr_char == '-')
                    addminus();

                ops.push(curr_char);
            }
        }

        addminus();

        return nums.empty() ? 0 : nums.top();
    }
};