//https://leetcode.cn/problems/swap-numbers-lcci/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        //��֤�ڴ����
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};