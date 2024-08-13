//https://leetcode.cn/problems/permutation-in-string/
//定长滑动窗口
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> scnt1(26, 0);
        vector<int> scnt2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            scnt1[s1[i] - 'a']++;
            scnt2[s2[i] - 'a']++;
        }
        int slow = 0, fast = s1.length();
        while (fast < s2.length()) {
            if (scnt1 == scnt2) {
                return true;
            }
            ++scnt2[s2[fast] - 'a'];
            --scnt2[s2[slow] - 'a'];
            slow++;
            fast++;
        }
        if (scnt1 == scnt2) {
            return true;
        }
        return false;
    }
};