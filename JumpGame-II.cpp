//https://leetcode.cn/problems/jump-game-ii/description/
//动态规划
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size()) {
                    //有回溯更新
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
//贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        //该区间中能跳的最远距离
        int maxfar = 0;
        //区间终点
        int end = 0;
        
        for (int i = 0; i < nums.size() - 1/*最后一个数并不需要遍历*/; i++) {
            if (maxfar >= i) {
                maxfar = max(maxfar, i + nums[i]);
                //当前区间完成遍历，更新区间
                //并且步数加1
                if (i == end) {
                    end = maxfar;
                    ans++;
                }
            }
        }
        return ans;
    }
};