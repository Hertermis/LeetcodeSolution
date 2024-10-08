//https://leetcode.cn/problems/decode-ways/description/
//��̬�滮
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0') {
                if ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.length()];
    }
};