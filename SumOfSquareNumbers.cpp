//https://leetcode.cn/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned left = 0, right = (int)sqrt(c);
        while (left <= right) {
            if (left * left + right * right == c) {
                return true;
            }
            else if (left * left + right * right > c) {
                right--;
            }
            else {
                left++;
            }
        }
        return false;
    }
};