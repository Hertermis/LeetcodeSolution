//https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/
//贪心-官方题解
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        //判断是否找到了0和5
        bool find0 = false, find5 = false;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0' || num[i] == '5') {
                //找到了0的基础上，又找到了0或者5，返回n-i-2
                if (find0) {
                    return n - i - 2;
                }
                //找到了第一个0，标记find0
                if (num[i] == '0') {
                    find0 = true;
                }
                //找到了第一个5，标记find5
                else {
                    find5 = true;
                }
            }
            else if (num[i] == '2' || num[i] == '7') {
                //找到了5后又找到2或者7，返回n-i-2
                if (find5) {
                    return n - i - 2;
                }
            }
        }
        //找到了唯一的0
        if (find0) {
            return n - 1;
        }
        return n;
    }
};