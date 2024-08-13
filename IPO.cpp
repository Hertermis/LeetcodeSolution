//https://leetcode.cn/problems/ipo/
class Solution {
public:
    struct Program {
        int profit;
        int capi;
        Program(int p, int c) : profit(p), capi(c) {};
    };
    class comAsProfit {
    public:
        bool operator()(Program& a, Program& b) { return a.profit < b.profit; }
    };
    class comAsCapital {
    public:
        bool operator()(Program& a, Program& b) { return a.capi > b.capi; }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits,
        vector<int>& capital) {
        vector<Program> items;
        for (int i = 0; i < profits.size(); i++) {
            items.emplace_back(Program(profits[i], capital[i]));
        }
        priority_queue<Program, vector<Program>, comAsCapital> pqCap(
            items.begin(), items.end());
        priority_queue<Program, vector<Program>, comAsProfit> pqPro;
        for (int i = 0; i < k; i++) {
            while (!pqCap.empty() && pqCap.top().capi <= w) {
                pqPro.emplace(pqCap.top());
                pqCap.pop();
            }
            if (pqPro.empty()) {
                return w;
            }
            w += pqPro.top().profit;
            pqPro.pop();
        }
        return w;
    }
};