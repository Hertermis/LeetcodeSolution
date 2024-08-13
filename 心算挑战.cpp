//https://leetcode.cn/problems/uOAnQW/description/?envType=daily-question&envId=2024-08-01
//Ì°ÐÄ
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), [](const int& a, const int& b) {
            return a > b;
            });
        int sum = 0;
        int minoddidx = -1;
        int minevenidx = -1;
        for (int i = 0; i < cnt; i++) {
            if (cards[i] % 2 == 1) {
                minoddidx = i;
            }
            else {
                minevenidx = i;
            }
            sum += cards[i];
        }
        if (sum % 2 == 0) {
            return sum;
        }
        int point1 = 0;
        int point2 = 0;
        for (int i = cnt; i < cards.size(); i++) {
            if (cards[i] % 2 == 0 && point1 == 0 && minoddidx != -1) {
                point1 = sum - cards[minoddidx] + cards[i];
            }
            else if (cards[i] % 2 == 1 && point2 == 0 && minevenidx != -1) {
                point2 = sum - cards[minevenidx] + cards[i];
            }
            else if (point2 != 0 && point1 != 0) {
                break;
            }
        }
        return max(point1, point2);
    }
};