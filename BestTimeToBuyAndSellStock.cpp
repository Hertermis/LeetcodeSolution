//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
//¶¯Ì¬¹æ»®
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minprice = min(minprice, prices[i]);
            ans = max(ans, prices[i] - minprice);
        }
        return ans;
    }
};