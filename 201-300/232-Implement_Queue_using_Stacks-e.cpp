//  Implement the following operations of a queue using stacks.

//     push(x) -- Push element x to the back of queue.
//     pop() -- Removes the element from in front of queue.
//     peek() -- Get the front element.
//     empty() -- Return whether the queue is empty.

// Notes:

//     You must use only standard operations of a stack -- which means only push
//     to top, peek/pop from top, size, and is empty operations are valid.
//     Depending on your language, stack may not be supported natively. You may
//     simulate a stack by using a list or deque (double-ended queue), as long
//     as you use only standard operations of a stack.
//     You may assume that all operations are valid (for example, no pop or
//     peek operations will be called on an empty queue).

class MyQueue {
    stack<int> in, out;
    // from source s to target t
    void tansfer(stack<int> &t, stack<int> &s) {
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
    }

  public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        if (in.empty())
            tansfer(in, out);
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty())
            tansfer(out, in);
        int ret = out.top();
        out.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (out.empty())
            tansfer(out, in);
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return in.empty() && out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */