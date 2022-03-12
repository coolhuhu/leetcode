#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：132. 分割回文串 II.py
@Author  ：lianghu
@Date    ：2022/3/5 12:55 
"""


class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        # f[i]表示 s[0:i]划分为回文子串的最小划分次数
        f = [20001] * n
        for j in range(1, n):
            for i in range(j):
                if j - i < 3:
                    if s[i] == s[j]:
                        dp[i][j] = True
                else:
                    if s[i] == s[j] and dp[i + 1][j - 1]:
                        dp[i][j] = True

        for i in range(n):
            if dp[0][i]:
                f[i] = 0
            else:
                for j in range(i):
                    if dp[j + 1][i]:
                        f[i] = min(f[i], f[j] + 1)

        return f[n - 1]
