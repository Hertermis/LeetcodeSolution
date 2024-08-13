//https://leetcode.cn/problems/jump-game-ii/description/
//��̬�滮
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size()) {
                    //�л��ݸ���
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
//̰��
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        //����������������Զ����
        int maxfar = 0;
        //�����յ�
        int end = 0;
        
        for (int i = 0; i < nums.size() - 1/*���һ����������Ҫ����*/; i++) {
            if (maxfar >= i) {
                maxfar = max(maxfar, i + nums[i]);
                //��ǰ������ɱ�������������
                //���Ҳ�����1
                if (i == end) {
                    end = maxfar;
                    ans++;
                }
            }
        }
        return ans;
    }
};