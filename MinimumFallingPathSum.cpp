//https://leetcode.cn/problems/minimum-falling-path-sum/?envType=study-plan-v2&envId=dynamic-programming
//动态规划+滚动数组
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        int cache1, cache2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    cache1 = dp[0];
                    dp[0] = min(cache1, dp[1]) + matrix[i][0];
                }
                else if (j == n - 1) {
                    dp[n - 1] = min(cache1, dp[n - 1]) + matrix[i][n - 1];
                }
                else {
                    cache2 = dp[j];
                    dp[j] = min(min(cache1, dp[j]), dp[j + 1]) + matrix[i][j];
                    cache1 = cache2;
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = ans < dp[i] ? ans : dp[i];
        }
        return ans;
    }
};