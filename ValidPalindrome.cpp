//https://leetcode.cn/problems/valid-palindrome/submissions/551905720/
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (is_alpha(s[left]) && is_alpha(s[right])) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                }
                else {
                    return false;
                }
            }
            if (!is_alpha(s[left])) {
                left++;
            }
            if (!is_alpha(s[right])) {
                right--;
            }
        }
        return true;
    }
    bool is_alpha(char& a) {
        return (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9');
    }
};