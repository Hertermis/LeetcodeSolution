//https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/?envType=daily-question&envId=2024-08-05
//暴力（超时）
class Solution {
public:
    int findIntegers(int n) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = i;
            while (tmp) {
                if ((tmp & 3) == 3) {
                    cnt++;
                    break;
                }
                tmp >>= 1;
            }
        }
        return n - cnt + 1;
    }
};
//动态规划
class Solution {
    unordered_map<int, int> map{ {0,1},{1,2},{2,3},{3,3} };
public:
    int findIntegers(int n) {
        auto it = map.find(n);
        if (it != map.end())return it->second;
        else return map[n] = findIntegers(n >> 1) + findIntegers((n - 1) >> 2);
    }
};
