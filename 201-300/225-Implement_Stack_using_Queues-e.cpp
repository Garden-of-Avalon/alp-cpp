// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to
// back, peek/pop from front, size, and is empty operations are valid. Depending
// on your language, queue may not be supported natively. You may simulate a
// queue by using a list or deque (double-ended queue), as long as you use only
// standard operations of a queue. You may assume that all operations are valid
// (for example, no pop or top operations will be called on an empty stack).

// TODO: think about one queue implementation
class MyStack {
    queue<int> q1;
    queue<int> q2;
    queue<int> *p_top = &q1; // may hold the top, or empty
    queue<int> *p_fil = &q2; // hold other elements
  public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        if (!p_top->empty()) {
            p_fil->push(p_top->front());
            p_top->pop();
        }
        p_fil->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = top();
        p_top->pop();
        return temp;
    }

    /** Get the top element. */
    int top() {
        if (p_top->empty()) {
            while (p_fil->size() > 1) {
                p_top->push(p_fil->front());
                p_fil->pop();
            }
            swap(p_fil, p_top);
        }
        return p_top->front();
    }

    /** Returns whether the stack is empty. */
    bool empty() { return p_top->empty() && p_fil->empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */