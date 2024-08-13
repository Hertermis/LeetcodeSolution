//https://leetcode.cn/problems/sort-colors/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		process(nums, 0, nums.size() - 1);
	}

	void process(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		pair<int, int> equ = partition(nums, left, right);
		process(nums, left, equ.first - 1);
		process(nums, equ.second + 1, right);
	}

	pair<int, int> partition(vector<int>& nums, int left, int right) {
		if (left == right) {
			return{ left,right };
		}
		int les = left - 1;
		int mor = right;
		int cur = left;
		while (cur < mor) {
			if (nums[cur] < nums[right]) {
				swap(nums[++les], nums[cur++]);
			}
			else if (nums[cur] == nums[right]) {
				cur++;
			}
			else {
				swap(nums[--mor], nums[cur]);
			}
		}
		swap(nums[right], nums[mor]);
		return { les + 1,mor };
	}
};