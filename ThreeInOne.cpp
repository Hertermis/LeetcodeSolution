//https://leetcode.cn/problems/three-in-one-lcci/
class TripleInOne {
    vector<int> TripleStack;
    int top1;
    int top2;
    int top3;
    int MAX_SIZE;
public:
    TripleInOne(int stackSize) {
        TripleStack.resize(3 * stackSize, 0);
        top1 = -1;
        top2 = stackSize - 1;
        top3 = 2 * stackSize - 1;
        MAX_SIZE = stackSize;
    }

    void push(int stackNum, int value) {
        switch (stackNum) {
        case 0:
            if (top1 == MAX_SIZE - 1) {
                return;
            }
            TripleStack[++top1] = value;
            break;
        case 1:
            if (top2 == 2 * MAX_SIZE - 1) {
                return;
            }
            TripleStack[++top2] = value;
            break;
        case 2:
            if (top3 == 3 * MAX_SIZE - 1) {
                return;
            }
            TripleStack[++top3] = value;
            break;
        }
    }

    int pop(int stackNum) {
        int ret = -1;
        switch (stackNum) {
        case 0:
            if (top1 == -1) {
                return ret;
            }
            ret = TripleStack[top1--];
            break;
        case 1:
            if (top2 == MAX_SIZE - 1) {
                return ret;
            }
            ret = TripleStack[top2--];
            break;
        case 2:
            if (top3 == 2 * MAX_SIZE - 1) {
                return ret;
            }
            ret = TripleStack[top3--];
            break;
        }
        return ret;
    }

    int peek(int stackNum) {
        int ret = -1;
        switch (stackNum) {
        case 0:
            if (top1 == -1) {
                break;
            }
            ret = TripleStack[top1];
            break;
        case 1:
            if (top2 == MAX_SIZE - 1) {
                break;
            }
            ret = TripleStack[top2];
            break;
        case 2:
            if (top3 == 2 * MAX_SIZE - 1) {
                break;
            }
            ret = TripleStack[top3];
            break;
        }
        return ret;
    }

    bool isEmpty(int stackNum) {
        bool ret = false;
        switch (stackNum) {
        case 0:
            if (top1 == -1) {
                ret = true;
            }
            break;
        case 1:
            if (top2 == MAX_SIZE - 1) {
                ret = true;
            }
            break;
        case 2:
            if (top3 == MAX_SIZE * 2 - 1) {
                ret = true;
            }
            break;
        }
        return ret;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */