#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：323. 无向图中连通分量的数目.py
@Author  ：lianghu
@Date    ：2022/3/12 18:27 
"""
import collections
from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjs = [[] for i in range(n)]

        # 构建无向图
        for edge in edges:
            adjs[edge[0]].append(edge[1])
            adjs[edge[1]].append(edge[0])

        # 记录已经访问过的节点
        visited = [False] * n

        def bfs(adjs, e, visited):
            que = collections.deque()
            que.append(e)
            visited[e] = True
            while len(que) != 0:
                node = que.popleft()
                edge = adjs[node]
                for e in edge:
                    if not visited[e]:
                        que.append(e)
                        visited[e] = True

        res = 0
        for i in range(n):
            if not visited[i]:
                bfs(adjs, i, visited)
                res += 1

        return res

