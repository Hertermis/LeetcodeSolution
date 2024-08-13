//https://leetcode.cn/problems/sort-of-stacks-lcci/
//最优时间复杂度
class SortedStack {
    stack<int> data;
    stack<int> tmp;
public:
    SortedStack() {}

    void push(int val) {
        if (data.empty()) {
            data.push(val);
        }
        else {
            while (!data.empty() && val > data.top()) {
                tmp.push(data.top());
                data.pop();
            }
            while (!tmp.empty() && val < tmp.top()) {
                data.push(tmp.top());
                tmp.pop();
            }
            data.push(val);
        }
    }

    void pop() {
        if (data.empty() && tmp.empty()) {
            return;
        }
        while (!tmp.empty()) {
            data.push(tmp.top());
            tmp.pop();
        }
        data.pop();
    }

    int peek() {
        if (data.empty() && tmp.empty()) {
            return -1;
        }
        while (!tmp.empty()) {
            data.push(tmp.top());
            tmp.pop();
        }
        return data.top();
    }

    bool isEmpty() { return data.empty() && tmp.empty(); }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
//较差时间复杂度
class SortedStack {
    stack<int> data;
    stack<int> tmp;
public:
    SortedStack() {

    }

    void push(int val) {
        if (data.empty()) {
            data.push(val);
        }
        else {
            while (!data.empty() && val > data.top()) {
                tmp.push(data.top());
                data.pop();
            }
            data.push(val);
            while (!tmp.empty()) {
                data.push(tmp.top());
                tmp.pop();
            }
        }
    }

    void pop() {
        if (data.empty()) {
            return;
        }
        data.pop();
    }

    int peek() {
        if (data.empty()) {
            return -1;
        }
        return data.top();
    }

    bool isEmpty() {
        return data.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
