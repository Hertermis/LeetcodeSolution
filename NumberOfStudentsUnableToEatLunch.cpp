//https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/description/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = 0, cnt = 0;
        queue<int> q;
        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            while (cnt < q.size()) {
                if (sandwiches[i] == q.front()) {
                    q.pop();
                    cnt = 0;
                    break;
                }
                else {
                    q.push(q.front());
                    q.pop();
                    cnt++;
                }
            }
        }
        return cnt;
    }
};