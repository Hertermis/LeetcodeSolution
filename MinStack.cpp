//https://leetcode.cn/problems/min-stack-lcci/
class MinStack {
public:
    stack<int> data;
    stack<int> min;
    /** initialize your data structure here. */
    MinStack() {

    }
    void push(int x) {
        data.push(x);
        if (min.empty()) {
            min.push(x);
            return;
        }
        min.push(x > min.top() ? min.top() : x);
    }
    void pop() {
        data.pop();
        min.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
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