//https://leetcode.cn/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxVol = 0;
        while (left < right) {
            maxVol = maxVol > min(height[left], height[right]) * (right - left) ?
                maxVol : min(height[left], height[right]) * (right - left);
            height[left] < height[right] ? left++ : right--;
        }
        return maxVol;
    }
};
/*
* ̰�ģ�
* ���������м������
* ÿ���ƶ���С����һ�ߣ�
* ��Ϊ�ƶ��ϴ����һ�ߣ�������ʹ�������
*/