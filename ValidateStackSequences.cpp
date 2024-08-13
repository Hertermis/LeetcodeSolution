//https://leetcode.cn/problems/validate-stack-sequences/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() < 3) {
            return true;
        }
        stack<int> s;
        int curPush = 0, curPop = 0;
        while (curPush < pushed.size()) {
            if (s.empty() || s.top() != popped[curPop]) {
                s.emplace(pushed[curPush]);
                curPush++;
            }
            if (!s.empty() && s.top() == popped[curPop]) {
                s.pop();
                curPop++;
            }
        }
        while (!s.empty()) {
            if (!s.empty() && s.top() == popped[curPop]) {
                s.pop();
                curPop++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};