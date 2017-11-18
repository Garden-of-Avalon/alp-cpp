// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     getMin() -- Retrieve the minimum element in the stack.
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

class MinStack {
  public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        data.push_back(x);
        // refer to MARK 1, here it has to be <=
        if (x <= minval.back())
            minval.push_back(x);
    }

    void pop() {
        if (!data.empty()) {
            // MARK 1
            if (data.back() == minval.back())
                minval.pop_back();
            data.pop_back();
        }
    }

    int top() { return data.back(); }

    int getMin() { return minval.back(); }

  private:
    std::vector<int> data;
    std::vector<int> minval{INT_MAX};
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/