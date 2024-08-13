//https://leetcode.cn/problems/build-an-array-with-stack-operations/description/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> ans;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (cur < target.size()) {
                if (target[cur] == i) {
                    ans.emplace_back("Push");
                    cur++;
                }
                else {
                    ans.emplace_back("Push");
                    ans.emplace_back("Pop");
                }
            }
        }
        return ans;
    }
};