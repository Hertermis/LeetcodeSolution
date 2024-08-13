//https://leetcode.cn/problems/powx-n/description/
//递归+快速幂
class Solution {
public:
    double myPow(double x, long long n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        if (n % 2 == 0) {
			return myPow(x * x, n / 2);
		}
		else {
			return x * myPow(x, n - 1);
		}
    }
};
//迭代+快速幂
class Solution {
public:
    double myPow(double x, long long n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        double ans = 1;
        long long d = n;
        if (d < 0) {
            x = 1 / x;
            d = -d;
        }
        while (d > 0) {
            if (d & 1) {
                ans *= x;
            }
            x *= x;
            d >>= 1;
        }
        return ans;
    }
};

