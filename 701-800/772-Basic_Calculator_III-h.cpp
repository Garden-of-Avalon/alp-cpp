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