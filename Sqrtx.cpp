//https://leetcode.cn/problems/sqrtx/description/
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, ans = 0;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((long long)mid * (long long)mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};