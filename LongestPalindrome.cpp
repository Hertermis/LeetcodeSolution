//https://leetcode.cn/problems/longest-palindrome/description/
class Solution {
public:
    int longestPalindrome(string s) {
        int hash[52]{ 0 };
        for (int i = 0; i < s.length(); i++) {

            s[i] - 'a' >= 0 ? hash[s[i] - 'a']++ : hash[s[i] - 'A' + 26]++;
        }
        int ans = 0;
        bool hasOdd = false;
        for (int i = 0; i < 52; i++) {
            if (hash[i] % 2 == 0) {
                ans += hash[i];
            }
            else {
                hasOdd = true;
                ans += hash[i] - 1;
            }

        }
        return hasOdd ? ans + 1 : ans;
    }
};