//https://leetcode.cn/problems/maximum-array-hopping-score-i/
//¶¯Ì¬¹æ»®
class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> m(nums.size(), 0);
        for (int j = 1; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                m[j] = max(nums[j] * (j - i) + m[i], m[j]);
            }
        }
        return m[nums.size() - 1];
    }
};