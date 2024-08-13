//https://leetcode.cn/problems/divisor-game/
//²©ÞÄÂÛ
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
//dp
class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
        }
        if (dp[n] % 2 == 0) {
            return false;
        }
        return true;
    }
};