//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left_idx = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    left_idx = mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (left_idx == -1) {
            return ans;
        }
        ans[0] = left_idx;
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    left_idx = mid;
                }
                left = mid + 1;

            }
            else {
                right = mid - 1;
            }
        }
        ans[1] = left_idx;
        return ans;
    }
};