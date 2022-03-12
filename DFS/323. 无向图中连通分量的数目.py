#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：323. 无向图中连通分量的数目.py
@Author  ：lianghu
@Date    ：2022/3/12 18:27 
"""
from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjs = [[] for _ in range(n)]
        for edge in edges:
            adjs[edge[0]].append(edge[1])
            adjs[edge[1]].append(edge[0])

        visited = [False] * n

        def dfs(adjs, e, visited):
            # 确定递归结束条件
            if visited[e]:
                return
            else:
                visited[e] = True
            for a in adjs[e]:
                dfs(adjs, a, visited)
            return

        res = 0
        for i in range(n):
            if not visited[i]:
                dfs(adjs, i, visited)
                res += 1

        return res

