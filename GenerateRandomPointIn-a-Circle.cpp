//https://leetcode.cn/problems/generate-random-point-in-a-circle/
//¾Ü¾ø²ÉÑù
class Solution {
public:
    double r, x0, y0;
    Solution(double radius, double x_center, double y_center)
        : r(radius), x0(x_center), y0(y_center) {}

    vector<double> randPoint() {
        random_device rd;
        default_random_engine e(rd());
        uniform_real_distribution<double> urd(-r, r);
        while (true) {
            double x = urd(e), y = urd(e);
            if (x * x + y * y <= r * r) {
                return { x0 + x, y0 + y };
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */


