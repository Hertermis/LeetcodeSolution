//https://leetcode.cn/problems/implement-rand10-using-rand7/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ret;
        do {
            ret = rand0_15();
        } while (ret == 0 || ret > 10);
        return ret;
    }
    //获取0-1等概率随机数
    int rand01() {
        int ret;
        do {
            ret = rand7();
        } while (ret == 4);
        if (ret > 4) {
            return 1;
        }
        return 0;
    }
    //生成等概率任意数（0~2^k-1）
    int rand0_15() {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            ret += rand01() << i;
        }
        return ret;
    }
};