//https://leetcode.cn/problems/is-subsequence/description/
//双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s.length() && p2 < t.length()) {
            if (s[p1] == t[p2]) {
                p1++;
            }
            p2++;
        }
        if (p1 == s.length()) {
            return true;
        }
        return false;
    }
};
//进阶：如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
//      你需要依次检查它们是否为 T 的子序列。
//      在这种情况下，你会怎样改变代码？
//dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(t.length() + 1, vector<int>(26, -1));
        //预处理
        for (int i = 0; i < 26; i++) {
            dp.back()[i] = -1;
        }
        for (int i = t.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (dp[i][j] == (t[i] - 'a')) {
                    //当移动到i，j位置时记录的是自己的i位置
                    dp[i][j] = i;
                }
                else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int dx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (dp[dx][s[i] - 'a'] == -1) {
                return false;
            }
            //直接跳到t中自己出现的位置之后一位
            dx = dp[dx][s[i] - 'a'] + 1;
        }
        return true;
    }
};

