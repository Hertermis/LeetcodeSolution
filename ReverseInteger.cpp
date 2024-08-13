//https://leetcode.cn/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = 0, dig = 0;
        while (x != 0) {
            /*无效if判断*/
            if (x != 0 && abs(ans) == INT_MAX / 10) {
                break;
            }/**/
            ans *= 10;
            dig = x % 10;
            ans += dig;
            x /= 10;
            if (x != 0 && abs(ans) > INT_MAX / 10) {
                return 0;
            }
        }
        /*无效if判断*/
        if (x != 0 && ans < 0 && ans == INT_MIN / 10) {
            int dif = INT_MIN - ans * 10 - x;
            if (dif > 0) {
                return 0;
            }
            else {
                return ans * 10 + x;
            }
        }
        if (x != 0 && ans > 0 && ans == INT_MAX / 10) {
            int dif = INT_MAX - ans * 10 - x;
            if (dif > 0) {
                return ans * 10 + x;
            }
            else {
                return 0;
            }
        }
        /**/
        return ans;
    }
};

//代码优化
class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = 0, dig = 0;
        while (x != 0) {
            ans *= 10;
            dig = x % 10;
            ans += dig;
            x /= 10;
            if (x != 0 && abs(ans) > INT_MAX / 10) {
                return 0;
            }
        }
        return ans;
    }
};