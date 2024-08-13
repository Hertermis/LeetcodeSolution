//https://leetcode.cn/problems/swap-numbers-lcci/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        //保证内存独立
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};