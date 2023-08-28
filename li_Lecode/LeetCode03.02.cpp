#include "pch.h"
#include <stack>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        m.push(INT_MAX);
    }

    void push(int x) {
        if (x < m.top())
            m.push(x);
        else
            m.push(m.top());
        s.push(x);
    }

    void pop() {
        s.pop();
        m.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */