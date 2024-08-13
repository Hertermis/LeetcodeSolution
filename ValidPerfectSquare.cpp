//https://leetcode.cn/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned left = 0, right = (1 << 16) - 1;
        while (left <= right) {
            unsigned mid = left + ((right - left) >> 1);
            unsigned squ = (unsigned)mid * (unsigned)mid;
            if (squ == num) {
                return true;
            }
            else if (squ > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};