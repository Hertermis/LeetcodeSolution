//https://leetcode.cn/problems/hanota-lcci/
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        process(A.size(), A, B, C);
    }
    void process(int n, vector<int>& origin, vector<int>& tmp,
        vector<int>& target) {
        if (n == 1) {
            target.emplace_back(origin.back());
            origin.pop_back();
            return;
        }
        process(n - 1, origin, target, tmp);
        target.emplace_back(origin.back());
        origin.pop_back();
        process(n - 1, tmp, origin, target);
    }
};