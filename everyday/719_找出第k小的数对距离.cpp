// 2022-06-15 每日一题  二分查找

// 排序之后可以使用二分查快速定位第 k 小的数对的范围区间
// 排序之后，最大的数对距离 max_distance =  nums[n-1] - nums[0]
// 则第k小的数对的值在 [0, max_distance] 范围内；
// 使用二分查找定位第k小的数对的距离


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums.back() - nums.front();
        while (left <= right) {
            // 二分查找第k小的数对距离
            int mid = left + (right - left) / 2;
            // cnt 变量记录所有小于等于mid的数对的数量
            int cnt = 0;

            // 计算所有小于等于mid的数对数目
            for (int i = 0; i < n; i++) {
                int j = lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin();
                cnt += i - j;
            }

            if (cnt >= k) {
                // 说明第k小的数对距离落在 [left, mid-1] 范围内
                right = mid - 1;
            }
            else {
                // 第k小的数对距离落在 [mid+1, right] 范围内
                left = mid + 1;
            }
        }
        return left;
    }
};