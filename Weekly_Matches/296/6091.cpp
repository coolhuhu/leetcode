// 6091. 划分数组使最大差为 K
// 因为只需求满足条件的最少划分次数，对实际操作是否改变序列顺序没有要求，
// 所以可以先进行排序，然后一次遍历求得结果。

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 1;
        sort(nums.begin(), nums.end());
        int _min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - _min > k) {
                cnt++;
                _min = nums[i];
            }
        }
        return cnt;
    }
};