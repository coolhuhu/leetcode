from typing import List


class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        res = 0
        prefix = 0
        record = {0: 0}
        n = len(nums)
        temp = 0
        for i in range(n):
            prefix += nums[i]
            temp = prefix - k
            if temp in record:
                res = max(res, i - record[temp] + 1)
            if prefix not in record:
                record[prefix] = i + 1
        return res
