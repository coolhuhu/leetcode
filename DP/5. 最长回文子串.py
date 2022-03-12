#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：5. 最长回文子串.py
@Author  ：lianghu
@Date    ：2022/3/4 21:13 
"""


class Solution:
    # 1. 确定dp数组及下标的含义：dp[i][j]表示 (s[i] ... s[j]) 的子串是否为回文子串，dp[i][j]=true表示是回文子串
    # 2. 状态转移方程：dp[i][j] 与 dp[i+1][j-1]有关，
    #  if (s[i] == s[j] && dp[i+1][j-1] == true) dp[i][j] = true
    # 3. dp数组初始化 dp[i][i] = true
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for i in range(n)]
        for i in range(n):
            dp[i][i] = True

        maxLen = 1
        left = 0
        for j in range(1, n):
            for i in range(j):
                if j - i < 3:
                    if s[i] == s[j]:
                        dp[i][j] = True
                        if j - i + 1 > maxLen:
                            maxLen = j - i + 1
                            left = i
                    else:
                        dp[i][j] = False
                else:
                    if s[i] == s[j]:
                        dp[i][j] = dp[i + 1][j - 1]
                        if dp[i][j] and j - i + 1 > maxLen:
                            maxLen = j - i + 1
                            left = i

                    else:
                        dp[i][j] = False

        return s[left: left + maxLen]
