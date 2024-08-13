//https://leetcode.cn/problems/majority-element-ii/
/*Ä¦¶ûÍ¶Æ±·¨*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt_1 = 0, flag1 = 0, cnt_2 = 0, flag2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt_1 == 0 && nums[i] != flag2) {
                flag1 = nums[i];
                cnt_1++;
                continue;
            }
            if (nums[i] == flag1) {
                cnt_1++;
                continue;
            }
            if (cnt_2 == 0 && nums[i] != flag1) {
                flag2 = nums[i];
                cnt_2++;
                continue;
            }
            if (nums[i] == flag2) {
                cnt_2++;
                continue;
            }
            cnt_1--;
            cnt_2--;
        }
        cnt_1 = 0, cnt_2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == flag1) {
                cnt_1++;
                continue;
            }
            if (nums[i] == flag2) {
                cnt_2++;
                continue;
            }
        }
        if (cnt_1 > nums.size() / 3) {
            ans.emplace_back(flag1);
        }
        if (cnt_2 > nums.size() / 3) {
            ans.emplace_back(flag2);
        }
        return ans;
    }
};