/*01����*/
//https://www.luogu.com.cn/problem/P2871
#include <iostream>
#include <vector>
using namespace std;
//Space O(m*n)
//Solution1�޷�ͨ�����⣬��Ϊ�ռ临�Ӷȹ���
class Solution1 {
public:
    int maxVal(vector<int>& weight, vector<int>& val, int capacity) {
        int n = weight.size();
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
        //dp[i][j]��ʾǰi����Ʒ����������Ϊjʱ������ֵ
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= capacity; j++) {
                //�����i����Ʒ���������ڱ���������
                //��ô��i����Ʒ���ܷ��뱳��
                //ֻ��Ҫ��ֵcopy��dp[i+1][j]
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
//�������� Space O(m)
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

/*��ȫ����*/
//https://www.luogu.com.cn/problem/P1616
class Solution {
public:
    long long maxVal_II(vector<long long>& costs, vector<long long>& values, long long time) {
        long long n = costs.size();
		vector<long long> dp(time + 1, 0);
        //��i����Ʒ�ɹ�ѡ��
        for (long long i = 0; i < n; i++) {
            //��ʼʱ��Ϊt
            for (long long t = costs[i]; t <= time; t++) {
                //�������Ҹ���dp[t]����t<costs[i]ʱ��dp[t]����
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

/*���ر���*/
/*���Ĵ���
*    for (int i = 1; i <= n; i++) {
*        for (int weight = W; weight >= w[i]; weight--) {
*            // �����һ����Ʒ����
*            for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
*                dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
*            }
*        }
*    }
*/
