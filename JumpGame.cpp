//https://leetcode.cn/problems/jump-game/
//Ì°ÐÄ
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdistance = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && maxdistance <= nums[i] + i && i != nums.size() - 1) {
                return false;
            }
            maxdistance = max(maxdistance, nums[i] + i);
        }
        return true;
    }
};