//https://leetcode.cn/problems/permutations/
//»ØËÝ·¨
class Solution {
    unordered_set<int> use;
    vector<vector<int>> ans;
    vector<int> input;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        process(nums);
        return ans;
    }
    void process(vector<int>& nums) {
        if (use.size() == nums.size()) {
            ans.emplace_back(input);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (use.find(nums[i]) == use.end()) {
                use.insert(nums[i]);
                input.emplace_back(nums[i]);
                process(nums);
                use.erase(nums[i]);
                input.pop_back();
            }
        }
    }
};