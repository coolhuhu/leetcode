// 第296场周赛第3题
// 6092. 替换数组中的元素
// 因为会存在链接替换的情况，例如 (1,3),(3,2),(2,4)...，这种情况下，1 最终被替换为了 4；
// 为了方便记录替换的元素对，从后往前遍历operations

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for (auto it = operations.rbegin(); it != operations.rend(); it++) {
            int x = (*it)[0];
            int y = (*it)[1];
            if (mp.count(y)) {
                mp[x] = mp[y];
            }
            else {
                mp[x] = y;
            }
        }
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                ans[i] = mp[nums[i]];
            }
            else {
                ans[i] = nums[i];
            }
        }
        return ans;
    }
};