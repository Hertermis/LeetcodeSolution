//https://leetcode.cn/problems/plus-one/description/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        digits.emplace_back(0);
        int i = 0;
        for (i = digits.size() - 2; i >= 0; i--) {
            if (digits[i] + carry == 10) {
                carry = 1;
                digits[i + 1] = 0;
            }
            else {
                digits[i + 1] = digits[i] + carry;
                carry = 0;
            }
        }
        if (carry) {
            digits[0] = 1;
            return digits;
        }
        digits.erase(digits.begin() + i + 1);
        return digits;
    }
};