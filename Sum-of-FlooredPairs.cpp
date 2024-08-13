//https://leetcode.cn/problems/sum-of-floored-pairs/
//暴力枚举（c++超时）
#define PRIME 1000000007
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long long> prefixSum(nums.size(), 0LL);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j >= 0; j--) {
                prefixSum[j] = (prefixSum[j] + nums[j] / nums[i]) % PRIME;
            }
        }
        long long ans = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            ans += prefixSum[i] % PRIME;
        }
        return ans;
    }
};
//前缀和+数学
class Solution {
    static constexpr int mod = 1000000007;
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        long long ans = 0LL;
        int upper = *max_element(nums.begin(), nums.end());
        vector<int> cnt(upper + 1, 0);
        for (int num : nums) {
            ++cnt[num];
        }
        vector<int> pre(upper + 1);
        for (int i = 1; i <= upper; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        for (int y = 1; y <= upper; ++y) {
            if (cnt[y]) {
                for (int d = 1; d * y <= upper; ++d) {
                    ans += (long long)cnt[y] * d * (pre[min((d + 1) * y - 1, upper)] - pre[d * y - 1]);
                }
            }
        }
        return ans % mod;
    }
};