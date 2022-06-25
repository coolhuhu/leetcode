// 2022-06-23
#include<vector>
using namespace std;


// 前缀和 + 暴力枚举
class Solution {
    int prefixSum[120][120];
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        // 二维前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int u = i; u <= m; u++) {
                    for (int v = j; v <= n; v++) {
                        // 暴力枚举上边界和下边界
                        int cur = prefixSum[u][v] - prefixSum[i-1][v] - prefixSum[u][j-1] + prefixSum[i-1][j-1];
                        if (cur <= k) {
                            ans = max(cur, ans);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

#include<set>

// 前缀和 + 二分
class Solution {    
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + matrix[i-1][j-1] - prefixSum[i-1][j-1];
            }
        }

        int ans = INT_MIN;
        for (int top = 1; top <= m; top++) {
            for (int bottom = top; bottom <= m; bottom++) {
                set<int> st{0};
                for (int right = 1; right <= n; right++) {
                    // 左边界为0，有边界为right，上下边界分别为top和bottom形成的矩阵
                    int rb = prefixSum[bottom][right] - prefixSum[top-1][right];
                    // 使用二分查找满足矩阵和小于k的最大值
                    auto lb = st.lower_bound(rb - k);
                    if (lb != st.end()) {
                        ans = max(ans, rb - *lb);
                    }
                    st.insert(rb);
                }
            }
        }
        return ans;
    }
};


// 优化空间，将二维前缀和优化为一维前缀和
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> prefixSum(n, 0);
            for (int j = i; j < m; j++) {
                // 在枚举子矩阵过程中求前缀和
                for (int c = 0; c < n; c++) {
                    prefixSum[c] += matrix[j][c];
                }
                set<int> st{0};
                int sum = 0;
                for (auto s : prefixSum) {
                    sum += s;
                    auto lb = st.lower_bound(sum - k);
                    if (lb != st.end()) {
                        ans = max(ans, sum - *lb);
                    }
                    st.insert(sum);
                }
            }
        }
        return ans;
    }
};