//https://leetcode.cn/problems/implement-queue-using-stacks/
class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */