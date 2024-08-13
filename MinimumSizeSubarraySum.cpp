//https://leetcode.cn/problems/minimum-size-subarray-sum/
//»¬¶¯´°¿Ú
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, fast = 0, sum = 0, ans = INT_MAX;
        while (fast < nums.size() && slow < nums.size()) {
            if (sum < target) {
                sum += nums[fast];
                fast++;
            }
            else {
                ans = min(ans, fast - slow);
                sum -= nums[slow];
                slow++;
            }
        }
        while (slow < nums.size()) {
            if (sum < target) {
                if (ans == INT_MAX) {
                    return 0;
                }
                return ans;
            }
            else {
                ans = min(ans, fast - slow);
                sum -= nums[slow];
                slow++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};