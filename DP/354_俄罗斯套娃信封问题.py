# 2022-06-24
import bisect
from typing import List


# 会超时
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
        


class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        
        envelopes.sort(key=lambda x : (x[0], -x[1]))

        dp = [envelopes[0][1]]
        for i in range(1, n):
            if num := envelopes[i][1] > dp[-1]:
                dp.append(num)
            else:
                index = bisect.bisect_left(dp, num)
                dp[index] = num
        
        return len(dp)