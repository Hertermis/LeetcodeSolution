//https://leetcode.cn/problems/majority-element/
/*¹þÏ£±í*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m.emplace(make_pair(nums[i], 1));
            }
            else {
                m[nums[i]]++;
            }
        }
        for (auto it : m) {
            if (it.second > nums.size() / 2) {
                ret = it.first;
            }
        }
        return ret;
    }
};
/*Ä¦¶ûÍ¶Æ±·¨*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                flag = nums[i];
                cnt++;
                continue;
            }
            if (nums[i] == flag) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return flag;
    }
};