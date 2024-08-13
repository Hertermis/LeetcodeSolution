//https://leetcode.cn/problems/string-to-url-lcci/
class Solution {
public:
    string replaceSpaces(string S, int length) {
        if (S.length() == length) {
            return S;
        }
        int cur = S.length() - 1;
        while (length) {
            if (S[length - 1] != ' ') {
                S[cur] = S[length - 1];
                cur--;
                length--;
            }
            else {
                S[cur] = '0';
                S[cur - 1] = '2';
                S[cur - 2] = '%';
                cur -= 3;
                length--;
            }
        }
        if (cur > -1) {
            S.erase(S.begin(), S.begin() + cur + 1);
        }
        return S;
    }
};