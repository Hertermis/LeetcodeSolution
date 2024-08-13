//https://leetcode.cn/problems/reverse-vowels-of-a-string/
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length();
        while (left < right) {
            if (!is_vowel(s[left])) {
                left++;
            }
            if (!is_vowel(s[right])) {
                right--;
            }
            if (is_vowel(s[left]) && is_vowel(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
    bool is_vowel(char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};