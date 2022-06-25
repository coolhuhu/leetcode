class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // 确定循环不变量为 [left , right]
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[0] <= nums[mid]) {    // 递增区间为 [0, mid]
                if (target >= nums[0] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {  // nums[mid] <= nums[n-1]
                if (target > nums[mid] && target <= nums[n-1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // 循环不变量为 [left, right)
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[0] <= nums[mid]) {
                if (target >= nums[0] && target < nums[mid]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[n-1]) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};