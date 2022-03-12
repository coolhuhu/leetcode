from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        prefix = 0
        record = {0: 1}
        for i in range(n):
            prefix += nums[i]
            temp = prefix - k
            if temp in record:
                res += record[temp]
            if prefix not in record:
                record[prefix] = 0
            record[prefix] += 1
        return res