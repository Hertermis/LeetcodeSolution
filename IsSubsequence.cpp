//https://leetcode.cn/problems/is-subsequence/description/
//˫ָ��
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
//���ף�����д�������� S������ S1, S2, ... , Sk ���� k >= 10�ڣ�
//      ����Ҫ���μ�������Ƿ�Ϊ T �������С�
//      ����������£���������ı���룿
//dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(t.length() + 1, vector<int>(26, -1));
        //Ԥ����
        for (int i = 0; i < 26; i++) {
            dp.back()[i] = -1;
        }
        for (int i = t.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (dp[i][j] == (t[i] - 'a')) {
                    //���ƶ���i��jλ��ʱ��¼�����Լ���iλ��
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
            //ֱ������t���Լ����ֵ�λ��֮��һλ
            dx = dp[dx][s[i] - 'a'] + 1;
        }
        return true;
    }
};

