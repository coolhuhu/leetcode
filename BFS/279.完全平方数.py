import collections


class Solution:
    # 动态规划
    # 1.确定dp数组及下标的含义：dp[i]表示和为 i 的完全平方数的最少数量
    # 2.确定地推公式：dp[i] = 1 + min(dp[1,i-j*j])
    def numSquares(self, n: int) -> int:
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            j = 1
            minN = n + 1
            while j * j <= i:
                minN = min(dp[i - j * j], minN)
                j += 1
            dp[i] = 1 + minN
        return dp[n]

    # # BFS
    # def numSquares(self, n: int) -> int:
    #     que = collections.deque()
    #     que.append(n)
    #     count = 1
    #     visited = [False] * (n + 1)
    #     while len(que) != 0:
    #         size = len(que)
    #         for i in range(size):
    #             cur = que.popleft()
    #             j = 1
    #             while j * j <= cur:
    #                 if j * j == cur:
    #                     # 说明cur是完全平方数，且不需要考虑比cur小的完全平方数了
    #                     return count
    #                 next = cur - j * j
    #                 if not visited[next]:
    #                     que.append(next)
    #                     visited[next] = True
    #                 j += 1
    #         count += 1
    #     return 0
