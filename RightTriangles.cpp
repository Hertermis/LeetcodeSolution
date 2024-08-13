//https://leetcode.cn/problems/right-triangles/description/?envType=daily-question&envId=2024-08-02
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> cnt_row(grid.size() + 1, 0);
        vector<int> cnt_col(grid[0].size(), 0);
        long long ans = 0ll;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    cnt_col[j]++;
                    cnt_row[i]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (cnt_col[j] > 1 && cnt_row[i] > 1) {
                        ans += (cnt_col[j] - 1) * (cnt_row[i] - 1);
                    }
                }
            }
        }
        return ans;
    }
};