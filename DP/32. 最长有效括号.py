
"""

"""

class Solution:
    # 定义dp数组及下标含义：dp[i] 表示以s[i]为子串末尾的最长有效括号子串的长度
    # 状态转移方程：
    # 当 s[i] == ')' and s[i-1] == '(' 时，dp[i] = dp[i-2] + 2
    # 当 s[i] == ')' and s[i-1] == ')' 时，dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2]
    # 初始化状态 dp[i] = 0
    def longestValidParentheses(self, s: str) -> int:
        """

        :param s:
        :return:
        """
        n = len(s)
        res = 0
        dp = [0] * n
        for i in range(1, n):
            if s[i] == ')':
                if s[i - 1] == '(':
                    if i >= 2:
                        dp[i] = dp[i - 2] + 2
                    else:
                        dp[i] = 2
                elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                    if i - dp[i - 1] - 2 >= 0:
                        dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
                    else:
                        dp[i] = dp[i - 1] + 2
                res = max(res, dp[i])
        return res
