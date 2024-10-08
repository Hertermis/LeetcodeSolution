//https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                ans++;
            }
        }
        return ans;
    }
};