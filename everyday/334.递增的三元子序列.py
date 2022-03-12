import sys


class Solution:

    # def increasingTriplet(self, nums: List[int]) -> bool:
    #     n = len(nums)
    #     if n < 3:
    #         return False
    #     leftMax = [0] * n
    #     leftMax[0] = nums[0]
    #     for i in range(1, n):
    #         leftMax[i] = min(leftMax[i - 1], nums[i])
    #     rightMax = [0] * n
    #     rightMax[n - 1] = nums[n - 1]
    #     for i in range(n - 2, -1, -1):
    #         rightMax[i] = max(nums[i], rightMax[i + 1])
    #
    #     for i in range(1, n - 1):
    #         if leftMax[i - 1] < nums[i] < rightMax[i + 1]:
    #             return True
    #
    #     return False


    # 贪心
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        first = nums[0]
        second = sys.maxsize
        for i in range(1, n):
            if nums[i] > second:
                return True
            elif first < nums[i] < second:
                second = nums[i]
            elif nums[i] < first:
                first = nums[i]
        return False