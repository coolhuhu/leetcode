// 2022-06-22


// leetcode 中会超时
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        // dp[i] 表示宽度为 envelopes[i][0], 高度为 envelopes[i][1] 的信封能装的最多信封数 
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};



// 基于二分查找的动态规划
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        // dp[i] 表示高度为 dp[i] 的信封最多能装 i 封
        vector<int> dp = {envelopes[0][1]};
        for (int i = 1; i < n; i++) {
            int num = envelopes[i][1];
            if (num > dp.back()) {
                dp.push_back(num);
            }
            else {
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();
    }
};