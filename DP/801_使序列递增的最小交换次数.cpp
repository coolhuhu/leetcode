// 2022-06-24

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // dp[i][0]表示nums1[i]和nums2[i]不交换时，0...i严格递增的最小交换次数
        // dp[i][1]表示nums1[i]和nums2[i]交换时，0...i严格递增的最小交换次数
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // 第一元素可交换，也可以不交换
        // 初始化状态，dp[0][0] = 0,dp[0][1] = 1;
        dp[0][0] = 0;
        dp[0][1] = 1;

        for (int i = 1; i < n; i++) {
            // nums1[0...i] 和 nums2[0...i] 都是严格递增的
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {
                // nums1[i]和nums2[i]交不交换都不会破坏严格递增的状态
                if (nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]) {
                    dp[i][0] = min(dp[i-1][0], dp[i-1][1]);// 不交换 nums1[i] 和 nums2[i]
                    dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;// 交换 nums1[i] 和 nums2[i]
                }
                else {  
                    dp[i][0] = dp[i-1][0]; // 若不交换，则i-1和i位置的元素都不发生交换
                    dp[i][1] = dp[i-1][1] + 1;// 若交换，则i-1和i位置的元素都发生交换
                }
            }
            else {
                dp[i][0] = dp[i-1][1];  // i-1位置交换，i位置不交换
                dp[i][1] = dp[i-1][0] + 1;  //i-1位置不交换，i位置交换
            }
        }

        return min(dp[n-1][0], dp[n-1][1]);
    }
};