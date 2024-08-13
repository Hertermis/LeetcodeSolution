//https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
//前缀和+位运算（利用位或计算奇偶）
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> cnt(s.length() + 1, 0);
        for (int i = 0; i < s.length(); i++) {
            cnt[i + 1] = cnt[i] ^ (1 << (s[i] - 'a'));
        }
        for (int i = 0; i < queries.size(); i++) {
            int _cnt = cnt[queries[i][0]] ^ cnt[queries[i][1] + 1];
            int bits = 0;
            while (_cnt > 0) {
                _cnt &= _cnt - 1;
                bits++;
            }
            ans.emplace_back(bits / 2 <= queries[i][2]);
        }
        return ans;
    }
};