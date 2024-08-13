//https://leetcode.cn/problems/single-number-iii/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[0] ^= nums.at(i);
        }
        int theRightOne = (ans[0] & (~ans[0] + 1));
        ans[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums.at(i) & theRightOne) != 0) {
                ans[0] ^= nums.at(i);
            }
            else {
                ans[1] ^= nums.at(i);
            }
        }
        return ans;
    }
};