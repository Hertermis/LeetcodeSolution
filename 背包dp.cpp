/*01背包*/
//https://www.luogu.com.cn/problem/P2871
#include <iostream>
#include <vector>
using namespace std;
//Space O(m*n)
//Solution1无法通过此题，因为空间复杂度过高
class Solution1 {
public:
    int maxVal(vector<int>& weight, vector<int>& val, int capacity) {
        int n = weight.size();
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
        //dp[i][j]表示前i个物品，背包容量为j时的最大价值
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= capacity; j++) {
                //如果第i个物品的重量大于背包容量，
                //那么第i个物品不能放入背包
                //只需要把值copy给dp[i+1][j]
                if (j <= weight[i]) {
					dp[i + 1][j] = dp[i][j];
				}
                else {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - weight[i]] + val[i]);
                }
            }
        }
        return dp[n][capacity];
    }
};
//滚动数组 Space O(m)
class Solution2 {
public:
    int maxVal(vector<int>& weight, vector<int>& val, int capacity) {
        int n = weight.size();
        vector<int> dp(capacity + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = capacity; j >= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
            }
        }
        return dp[capacity];
    }
};
int main() {
    int n, Bag;
    scanf("%d %d", &n, &Bag);
    vector<int> Wi(n, 0);
    vector<int> Di(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &Wi[i], &Di[i]);
    }
    Solution2 solution;
    cout << solution.maxVal(Wi, Di, Bag) << endl;
    return 0;
}

/*完全背包*/
//https://www.luogu.com.cn/problem/P1616
class Solution {
public:
    long long maxVal_II(vector<long long>& costs, vector<long long>& values, long long time) {
        long long n = costs.size();
		vector<long long> dp(time + 1, 0);
        //有i种物品可供选择
        for (long long i = 0; i < n; i++) {
            //初始时间为t
            for (long long t = costs[i]; t <= time; t++) {
                //从左往右更新dp[t]，当t<costs[i]时，dp[t]不变
                dp[t] = max(dp[t], dp[t - costs[i]] + values[i]);
            }
        }
		return dp[time];
    }
};
int main() {
    long long n, time;
    scanf("%lld %lld", &time, &n);
    vector<long long> costs(n, 0);
    vector<long long> values(n, 0);
    for (long long i = 0; i < n; i++) {
        scanf("%lld %lld", &costs[i], &values[i]);
    }
    Solution s;
    cout << s.maxVal_II(costs, values, time) << endl;
    return 0;
}

/*多重背包*/
/*核心代码
*    for (int i = 1; i <= n; i++) {
*        for (int weight = W; weight >= w[i]; weight--) {
*            // 多遍历一层物品数量
*            for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
*                dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
*            }
*        }
*    }
*/
