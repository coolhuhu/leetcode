#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：413. 等差数列划分.py
@Author  ：lianghu
@Date    ：2022/2/28 21:44 
"""
from typing import List


class Solution:
    # 定义dp数组及下标含义：dp[i]表示以nums[i]为末尾元素的等差数列的个数
    # 递推公式：
    # 如果 nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2], dp[i] = dp[i - 1] + 1
    # 初始化：dp[i] = 0
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        dp = [0] * n
        for i in range(2, n):
            if nums[i] + nums[i - 2] == 2 * nums[i - 1]:
                dp[i] = dp[i - 1] + 1
        return sum(dp)
