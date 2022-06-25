// 2022-06-25

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3, 0);
        for (int i = 0; i < 3; i++) {
            dp[i] = costs[0][i];
        }
        for (int i = 1; i < n; i++) {
            vector<int> tmp(3, 0);
            for (int j = 0; j < 3; j++) {
                tmp[j] = min(dp[(j+1) % 3], dp[(j+2) % 3]) + costs[i][j];
            }
            dp = tmp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};