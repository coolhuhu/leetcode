import heapq
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        res = []
        m = len(nums1)
        n = len(nums2)
        hq = [(nums1[i] + nums2[i], i, 0) for i in range(min(k, m))]
        while hq and k > 0:
            _, x, y = heapq.heappop(hq)
            res.append([nums1[x], nums2[y]])
            if y + 1 < n:
                heapq.heappush(hq, (nums1[x] + nums2[y], x, y + 1))
        return res

