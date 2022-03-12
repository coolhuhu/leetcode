#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：91. 解码方法.py
@Author  ：lianghu
@Date    ：2022/2/28 22:27 
"""


class Solution:
    # 定义dp数组及下标含义：dp[i]表示nums[0]...nums[i]解码方法的总数
    # 递推公式：
    #
    # def numDecodings(self, s: str) -> int:
    #     n = len(s)
    #     dp = [0] * (n + 1)
    #     dp[0] = 1
    #     for i in range(1, n + 1):
    #         if s[i - 1] != '0':
    #             dp[i] += dp[i - 1]
    #         if i > 1 and s[i - 2] != '0' and 0 < int(s[i - 2: i]) <= 26:
    #             dp[i] += dp[i - 2]
    #     return dp[n]

    def numDecodings(self, s: str) -> int:
        n = len(s)
        # a = dp[i-2], b = dp[i-1], c = dp[i]
        a, b, c = 0, 1, 0
        for i in range(1, n+1):
            if s[i - 1] != '0':
                c += b
            if i > 1 and s[i - 2] != '0' and 0 < int(s[i - 2: i]) <= 26:
                c += a
            b, a = c, b
        return c

