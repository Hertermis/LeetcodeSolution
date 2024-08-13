//https://leetcode.cn/problems/one-away-lcci/
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (abs((int)first.length() - (int)second.length()) >= 2) {
            return false;
        }
        int cnt = 0;
        int p1 = 0, p2 = 0;
        if (abs((int)first.length() - (int)second.length()) == 1) {
            while (p1 < first.length() && p2 < second.length()) {
                if (first[p1] == second[p2]) {
                    p1++;
                    p2++;
                }
                else {
                    // ���Ƶ�һ����ͬ�������ȱλ
                    break;
                }
            }
            first.length() > second.length() ? p1++ : p2++;
            while (p1 < first.length() && p2 < second.length()) {
                if (first[p1] == second[p2]) {
                    p1++;
                    p2++;
                }
                else {
                    // �Ѿ����ڶ��α༭
                    return false;
                }
            }
        }
        else {
            while (p1 < first.length() && p2 < second.length()) {
                if (first[p1] != second[p2]) {
                    if (cnt == 1) {
                        return false;
                    }
                    cnt++;
                }
                p1++;
                p2++;
            }
        }
        return true;
    }
};