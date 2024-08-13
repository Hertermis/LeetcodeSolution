//https://leetcode.cn/problems/check-if-array-is-good/description/
class Solution {
    int hash[220]{};
public:
    bool isGood(vector<int>& nums) {
        hash[0] = 1;
        int max = 0;
        bool ans = true;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        for (int i = 1; i < max; i++) {
            if (hash[i] != 1) {
                return false;
            }
        }
        if (hash[max] != 2) {
            return false;
        }
        return true;
    }
};