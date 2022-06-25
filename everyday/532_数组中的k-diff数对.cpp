// 2022-06-16 每日一题 哈希表、二分查找

// 哈希表
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> ans;
        for (int num : nums) {
            if (visited.count(num - k)) {
                ans.emplace(num - k);
            }
            if (visited.count(num + k)) {
                ans.emplace(num);
            }
            visited.emplace(num);
        }
        return ans.size();
    }
};


// 二分查找
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<pair<int, int>> st;
        int left = 0, right = 0;
        while (right < n) {
            int diff = nums[right] - nums[left];
            if (right != left) {
                if (diff == k) {
                    st.insert({nums[left], nums[right]});
                    left++;
                    right++;
                }
                else if (diff < k) {
                    right++;
                }
                else {
                    left++;
                }
            }
            else {
                right++;
            }
        }
        return st.size();
    }
};