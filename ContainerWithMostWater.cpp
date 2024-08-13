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
* 贪心：
* 从两边向中间遍历，
* 每次移动较小的那一边，
* 因为移动较大的那一边，不可能使面积增大
*/