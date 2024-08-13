//https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/
//̰��-�ٷ����
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        //�ж��Ƿ��ҵ���0��5
        bool find0 = false, find5 = false;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0' || num[i] == '5') {
                //�ҵ���0�Ļ����ϣ����ҵ���0����5������n-i-2
                if (find0) {
                    return n - i - 2;
                }
                //�ҵ��˵�һ��0�����find0
                if (num[i] == '0') {
                    find0 = true;
                }
                //�ҵ��˵�һ��5�����find5
                else {
                    find5 = true;
                }
            }
            else if (num[i] == '2' || num[i] == '7') {
                //�ҵ���5�����ҵ�2����7������n-i-2
                if (find5) {
                    return n - i - 2;
                }
            }
        }
        //�ҵ���Ψһ��0
        if (find0) {
            return n - 1;
        }
        return n;
    }
};