// 2022-06-07 每日一题
// 875. 爱吃香蕉的珂珂


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(pile, maxPile);
        }
        int l = 1, r = maxPile;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool flag = costTime(piles, mid, h);
            if (flag) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r + 1;
    }

    bool costTime(vector<int>& piles, int k, int h) {
        for (int pile : piles) {
            int tmp = pile % k;
            h -= pile / k;
            if (tmp > 0) {
                h -= 1;
            }
            if (h < 0) {
                return false;
            }
        }
        return true;
    }
};