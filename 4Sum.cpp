//https://leetcode.cn/problems/4sum/submissions/551719174/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (static_cast<long long>(nums[i])
                + static_cast<long long>(nums[i + 1])
                + static_cast<long long>(nums[i + 2])
                + static_cast<long long>(nums[i + 3]) > static_cast<long long>(target)) {
                break;
            }
            if (static_cast<long long>(nums[i])
                + static_cast<long long>(nums[n - 3])
                + static_cast<long long>(nums[n - 2])
                + static_cast<long long>(nums[n - 1]) < static_cast<long long>(target)) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (static_cast<long long>(nums[i])
                    + static_cast<long long>(nums[j])
                    + static_cast<long long>(nums[j + 1])
                    + static_cast<long long>(nums[j + 2]) > static_cast<long long>(target)) {
                    break;
                }
                if (static_cast<long long>(nums[i])
                    + static_cast<long long>(nums[j])
                    + static_cast<long long>(nums[n - 2])
                    + static_cast<long long>(nums[n - 1]) < static_cast<long long>(target)) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (static_cast<long long>(nums[i])
                        + static_cast<long long>(nums[j])
                        + static_cast<long long>(nums[left])
                        + static_cast<long long>(nums[right]) == static_cast<long long>(target)) {
                        ans.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                    else if (static_cast<long long>(nums[i])
                        + static_cast<long long>(nums[j])
                        + static_cast<long long>(nums[left])
                        + static_cast<long long>(nums[right]) > static_cast<long long>(target)) {
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                    else {
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};