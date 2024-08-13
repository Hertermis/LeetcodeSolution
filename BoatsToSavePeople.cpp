//https://leetcode.cn/problems/boats-to-save-people/submissions/548573450/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] > limit) {
                right--;
                ans++;
            }
            else {
                right--;
                left++;
                ans++;
            }
        }
        return ans;
    }
};