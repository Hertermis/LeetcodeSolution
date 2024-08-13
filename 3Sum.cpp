//https://leetcode.cn/problems/3sum/submissions/551116400/
//Ë«Ö¸Õë+ÅÅÐò
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int target = nums[i];
            int left = i + 1, right = nums.size() - 1;
            if (i > 0 && target == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                if (target + nums[right] + nums[left] > 0) {
                    right--;
                }
                else if (target + nums[right] + nums[left] < 0) {
                    left++;
                }
                else {
                    vector<int> tmp(3, 0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ans.emplace_back(tmp);
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};