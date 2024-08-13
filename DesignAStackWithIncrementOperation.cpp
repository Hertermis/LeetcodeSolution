//https://leetcode.cn/problems/design-a-stack-with-increment-operation/
class CustomStack {
    vector<int> emulationStack;
    int MAX_SIZE;
public:
    CustomStack(int maxSize) {
        emulationStack.reserve(maxSize);
        MAX_SIZE = maxSize;
    }

    void push(int x) {
        if (emulationStack.size() != MAX_SIZE) {
            emulationStack.emplace_back(x);
        }
    }

    int pop() {
        if (emulationStack.size() != 0) {
            int tmp = emulationStack.back();
            emulationStack.pop_back();
            return tmp;
        }
        return -1;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < emulationStack.size(); i++) {
            emulationStack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */