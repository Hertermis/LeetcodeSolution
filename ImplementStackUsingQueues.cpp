//https://leetcode.cn/problems/implement-stack-using-queues/
class MyStack {
    queue<int>* data;
    queue<int>* help;

public:
    MyStack() {
        data = new queue<int>();
        help = new queue<int>();
    }

    void push(int x) { data->emplace(x); }

    int pop() {
        while (data->size() != 1) {
            int tmp = data->front();
            data->pop();
            help->push(tmp);
        }
        int tmp = data->front();
        data->pop();
        queue<int>* p = data;
        data = help;
        help = p;
        return tmp;
    }

    int top() {
        while (data->size() != 1) {
            int tmp = data->front();
            data->pop();
            help->push(tmp);
        }
        int tmp = data->front();
        data->pop();
        help->push(tmp);
        queue<int>* p = data;
        data = help;
        help = p;
        return tmp;
    }

    bool empty() {
        if (data->empty() && help->empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */