from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        prefix = 0
        record = {0: 0}
        for i in range(n):
            if nums[i] <= 0:
                prefix += -1
            else:
                prefix += 1
            if prefix in record:
                res = max(res, i - record[prefix] + 1)
            if prefix not in record:
                record[prefix] = i + 1
        return res