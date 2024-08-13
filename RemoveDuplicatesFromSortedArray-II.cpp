//https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
//����+˫ָ��
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == flag) {
                cnt++;
                if (cnt > 2) {
                    nums[i] = nums[0] - 1;
                }
            }
            else {
                flag = nums[i];
                cnt = 1;
            }
        }
        int fast = 0, slow = 0;
        while (slow < nums.size() && fast < nums.size() && nums[slow] != nums[0] - 1) {
            fast++;
            slow++;
        }
        while (fast < nums.size()) {
            if (nums[fast] == nums[0] - 1) {
                fast++;
            }
            else {
                swap(nums[fast], nums[slow]);
                fast++;
                slow++;
            }
        }
        return slow;
    }
};
//������˫ָ��
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
//���ߣ����۹ٷ����
//���ӣ�https ://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/702644/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-yec2/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
//����
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i<2 || num>nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};