//https://leetcode.cn/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (isBadVersion(mid) == true) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};